/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:26:02 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/21 11:26:04 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/usr/include/minilibx-linux/mlx.h"
# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_texture
{
	void			*wall;
	void			*collectable;
	void			*enemy_animation1;
	void			*enemy_animation2;
	void			*player;
	void			*exit;
	void			*empty_space;
	void			*player_e;
	void			*player_a;
}					t_textures;

typedef struct s_flood_fill
{
	int				i;
	int				j;
	int				x;
	int				y;
	int				collectibles;
	int				exit;
	int				counter;
}					t_flood_fill;

typedef struct s_map
{
	char			**map;
	int				rows;
	int				columns;
}					t_map;

typedef struct s_player
{
	int				player_x;
	int				player_y;
	int				moves;
}					t_player;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_textures		textures;
	t_map			map;
	t_player		player;
	int				width;
	int				hight;
	int				keycode;
	int				frame_slower;
	unsigned int	frame_counter;
}					t_game;

char				**read_map(char *file, int rows);
int					count_rows(char *file);
int					count_columns(char *columns);
void				put_image_in_window(t_game **game, int keycode);
void				init_textures(int tail_size, t_game **game);
void				init_window(int tail_size, t_game **game);
void				move_player(t_game **game, int dx, int dy, int keycode);
void				player_position(t_map *map, int *x, int *y);
int					key_press(int keycode, t_game **game);
int					exit_game(t_game **game);
void				if_empty_space_(t_game **game, int new_x, int new_y,
						int keycode);
int					no_collectable_left(t_game **game);
void				init_image(t_game **game, int x, int y, int cord[2]);
void				game_loop(t_game **game);
void				get_player_position(char **map, int *x, int *y);
int					no_collectable_left(t_game **game);
int					count_columns(char *columns);
void				ft_free(char **map);
int					no_collectables(char **map);
int					no_player(char **map);
int					no_exit(char **map);
int					no_enemy(char **map);
int					valid_map(char **map, t_game *game);
int					nrm_loop(t_game **game, int x[3], int rows, int columns);
void				flood_fill(char **map, int x, int y, t_flood_fill *f);
int					valid_path(char **map);
int					count_collectables(char **map);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa(int n);
int					check_map(char **map);
size_t				ft_len(char *map);
int					check_map_rules(char **map);
int					first_row_norm(int *j, char *map);
#endif
