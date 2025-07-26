# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 14:01:50 by lanton-m          #+#    #+#              #
#    Updated: 2025/07/25 14:01:50 by lanton-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := push_swap
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -Ilibft -Iprintf

LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/libft.a

PRINTF_DIR  := printf
PRINTF      := $(PRINTF_DIR)/libftprintf.a

SRC         := push_swap.c operations_1.c operations_2.c organizers_1.c  organizers_2.c cleaners.c parser.c \
				stack_creation_1.c stack_creation_2.c utils.c
OBJ         := $(SRC:.c=.o)

all: $(LIBFT) $(PRINTF) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
