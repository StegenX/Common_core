NAME = push_swap

NAME2 = checker

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = get_target.c helper_functions.c libft_functions3.c main_push_swap.c push.c rev_rotate.c sort.c appened.c get_index.c helper_functions2.c libft_functions2.c libft_functions.c \
      main_instraction.c move.c rotate.c swap.c

BONUS = bonus/checker.c bonus/checker_utils.c bonus/get_target.c bonus/helper_functions.c bonus/libft_functions3.c bonus/push.c bonus/rev_rotate.c bonus/sort.c bonus/appened.c \
		bonus/get_index.c bonus/helper_functions2.c bonus/libft_functions2.c bonus/libft_functions.c \
		bonus/main_instraction.c bonus/move.c bonus/rotate.c bonus/swap.c bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME2)

$(NAME) : $(OBJ)
	cc $(FLAGS)  $(OBJ) -o $(NAME)

$(NAME2) : $(BONUS_OBJ)
	cc $(FLAGS) $(BONUS_OBJ) -o $(NAME2)

clean : 
	rm -f $(OBJ) $(BONUS_OBJ)

fclean :
	rm -f $(NAME) $(NAME2) $(OBJ) $(BONUS_OBJ)

re : fclean all

.PHONY : all clean fclean bonus re
