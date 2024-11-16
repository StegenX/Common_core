NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC =	ft_putchar.c ft_put_hex_upper.c ft_putnbr_unsigned.c ft_putstr.c \
	ft_printf.c ft_put_hex_lower.c ft_putnbr.c ft_put_pointer.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
