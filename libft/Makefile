
SRC = ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memchr.c ft_memmove.c ft_putendl_fd.c ft_split.c ft_striteri.c ft_strlcpy.c ft_strncmp.c ft_strtrim.c ft_toupper.c \
	ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcmp.c ft_memset.c ft_putnbr_fd.c ft_strchr.c ft_strjoin.c ft_strlen.c ft_strnstr.c ft_substr.c \
	ft_calloc.c ft_isascii.c ft_itoa.c ft_memcpy.c ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c ft_strlcat.c ft_strmapi.c ft_strrchr.c ft_tolower.c

OBJS = ${SRC:%.c=%.o}

NAME = libft.a

CC = cc -Wall -Werror -Wextra -I .
RM = rm -f
AR = ar rcs

CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

%.c: %.o
	${CC} ${CFLAGS} -c $@ -o $<

$(NAME): ${OBJS}
	${AR} ${NAME} ${OBJS}

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJS)
clean:
			${RM} ${OBJS}

fclean:	clean
			${RM} $(NAME)

re: fclean all

.PHONY:	all clean fclean re
