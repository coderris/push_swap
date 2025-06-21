CC      := cc
CFLAGS  := -Wall -Wextra -Werror
AR      := ar rcs

NAME    := push_swap.a

LIBFT_DIR  := libft
LIBFT      := $(LIBFT_DIR)/libft.a

PRINTF_DIR  := printf
PRINTF      := $(PRINTF_DIR)/printf.a
SRC     := 
OBJ     := $(SRC:.c=.o)


all: $(LIBFT) $(PRINTF) $(NAME)


$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@rm -f $(NAME)
	@mkdir -p temp_libft_objs
	@cd temp_libft_objs && ar x ../$(LIBFT)
	$(AR) $(NAME) $(OBJ) temp_libft_objs/*.o
	@rm -rf temp_libft_objs


%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)


fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)


re: fclean all


.PHONY: all clean fclean re