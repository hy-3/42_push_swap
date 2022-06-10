NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC_DIR = src
CONV_DIR = conversion
UTIL_DIR = util
SRC = \
	$(SRC_DIR)/ft_printf.c \
	$(CONV_DIR)/c_conv.c \
	$(CONV_DIR)/s_conv.c \
	$(CONV_DIR)/p_conv.c \
	$(CONV_DIR)/d_i_conv.c \
	$(CONV_DIR)/u_conv.c \
	$(CONV_DIR)/x_conv.c \
	$(UTIL_DIR)/is_char_match.c \
	$(UTIL_DIR)/base_ten_power.c \
	$(UTIL_DIR)/cust_putnbr_int.c \
	$(UTIL_DIR)/cust_putnbr_unsigned_int.c \
	$(UTIL_DIR)/cust_putchar.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -rf $(OBJ)

.PHONY: all re fclean clean
