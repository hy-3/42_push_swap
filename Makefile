NAME = push_swap
CC = gcc
# FLAGS = -Wall -Wextra -Werror
# FLAGS = -fsanitize=address
FT_PRINTF_PATH = util/ft_printf
FT_PRINTF = util/ft_printf/libftprintf.a
O = operation
SRC = \
		src/main.c \
		src/$(O)/swap.c \
		src/$(O)/push.c \
		src/$(O)/rotate.c \
		src/$(O)/reverse_rotate.c \
		util/atoi.c \
		util/str_split.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(FT_PRINTF_PATH)
	$(CC) $(FLAGS) $(OBJ) $(FT_PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

re: fclean all

fclean: clean
	rm -f push_swap
	rm -f $(FT_PRINTF)

clean:
	make clean -C $(FT_PRINTF_PATH)
	rm -f $(OBJ)

.phony = all re fclean clean