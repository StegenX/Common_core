/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:34:38 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/20 18:36:26 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(int tail_size, t_game **game)
{
	(*game)->player.moves = 0;
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	(*game)->window = mlx_new_window((*game)->mlx, (*game)->map.columns
			* tail_size, (*game)->map.rows * tail_size, "hehe");
	if (!(*game)->window)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

char	**read_map(char *file, int rows)
{
	int		fd;
	char	*line;
	int		i;
	char	**map;

	line = NULL;
	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char *) * (rows + 1));
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	put_image_in_window(t_game **game, int keycode)
{
	int	x[3];
	int	y[2];

	y[0] = 0;
	x[0] = 0;
	x[1] = 0;
	x[2] = 0;
	if (keycode == 'd')
		x[2] = 0;
	else if (keycode == 'a')
		x[2] = 1;
	while (y[0] < (*game)->map.rows)
	{
		y[1] = 0;
		while (y[1] < (*game)->map.columns)
		{
			x[0] = y[1] * 32;
			x[1] = y[0] * 32;
			if (!nrm_loop(game, x, y[0], y[1]))
				init_image(game, x[0], x[1], y);
			y[1]++;
		}
		y[0]++;
	}
}

void	player_position(t_map *map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->map[i][j] == 'P')
			{
				*y = i;
				*x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
