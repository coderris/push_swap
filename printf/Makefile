# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 17:35:20 by lanton-m          #+#    #+#              #
#    Updated: 2025/03/08 17:35:20 by lanton-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      := cc
CFLAGS  := -Wall -Wextra -Werror -Ilibft -Iprintf
AR      := ar rcs

NAME    := libftprintf.a

LIBFT_DIR  := ../libft
LIBFT      := $(LIBFT_DIR)/libft.a

SRC     := ft_printf.c ft_case.c ft_xcase.c ft_idcase.c ft_pcase.c \
			ft_scase.c ft_times_hex.c ft_ucase.c ft_putnbr_hex_fd.c ft_putnbr_x_fd.c
OBJ     := $(SRC:.c=.o)


all: $(LIBFT) $(NAME)


$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)


$(NAME): $(OBJ) $(LIBFT)
	@rm -f $(NAME)
	@mkdir -p temp_libft_objs
	@cd temp_libft_objs && ar x ../$(LIBFT)
	$(AR) $(NAME) $(OBJ) temp_libft_objs/*.o
	@rm -rf temp_libft_objs


%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)


fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)


re: fclean all


.PHONY: all clean fclean re
