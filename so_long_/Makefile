NAME = so_long

BNAME = so_long_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC = so_long.c libft.c helpers.c init_image.c init_window.c check_map.c check_path.c move.c gnl/get_next_line.c gnl/get_next_line_utils.c

BONUS_SRC = so_long_bonus.c libft_bonus.c helpers_bonus.c init_image_bonus.c init_window_bonus.c check_map_bonus.c \
			check_path_bonus.c move_bonus.c gnl/get_next_line.c gnl/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

bonus: $(BNAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L/usr/include/minilibx-linux/ -lmlx -lXext -lX11 -o $(NAME)

$(BNAME): $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) -L/usr/include/minilibx-linux/ -lmlx -lXext -lX11 -o $(BNAME)

clean:
	rm -f $(OBJ) $(BONUS_OBJ) 

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all bonus

.PHONY: all clean fclean re bonus
