NAME = philo

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

SRC = philosophers.c helper.c action.c init_philo.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

.PHONY : clean fclean all  
