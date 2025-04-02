NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = philosophers.c helper.c action.c init_philo.c set.c check.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

cl :
	clear
ra : all clean cl

.PHONY : clean fclean all  
