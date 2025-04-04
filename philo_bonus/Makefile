NAME = philo_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = philosophers_bonus.c helper_bonus.c action_bonus.c init_philo_bonus.c set_bonus.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY : clean fclean all re
