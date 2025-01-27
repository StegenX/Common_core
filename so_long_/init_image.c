/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:38:32 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/21 11:43:10 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_game **game, int x, int y, int cord[2])
{
	if ((*game)->map.map[cord[0]][cord[1]] == '1')
		mlx_put_image_to_window((*game)->mlx, (*game)->window,
			(*game)->textures.wall, x, y);
	else if ((*game)->map.map[cord[0]][cord[1]] == 'C')
		mlx_put_image_to_window((*game)->mlx, (*game)->window,
			(*game)->textures.collectable, x, y);
	else if ((*game)->map.map[cord[0]][cord[1]] == '0')
		mlx_put_image_to_window((*game)->mlx, (*game)->window,
			(*game)->textures.empty_space, x, y);
}

void	if_empty_space_(t_game **game, int new_x, int new_y, int keycode)
{
	if ((*game)->map.map[(*game)->player.player_y]
		[(*game)->player.player_x] == 'E')
	{
		(*game)->map.map[(*game)->player.player_y]
		[(*game)->player.player_x] = 'E';
		(*game)->player.player_x = new_x;
		(*game)->player.player_y = new_y;
		(*game)->map.map[new_y][new_x] = 'P';
		(*game)->player.moves++;
		ft_putnbr_fd((*game)->player.moves, 1);
		write(1, "\n", 1);
		put_image_in_window(game, keycode);
	}
	else
	{
		(*game)->map.map[(*game)->player.player_y]
		[(*game)->player.player_x] = '0';
		(*game)->player.player_x = new_x;
		(*game)->player.player_y = new_y;
		(*game)->map.map[new_y][new_x] = 'P';
		(*game)->player.moves++;
		ft_putnbr_fd((*game)->player.moves, 1);
		write(1, "\n", 1);
		put_image_in_window(game, keycode);
	}
}

void	init_textures(int tail_size, t_game **game)
{
	(*game)->textures.wall = mlx_xpm_file_to_image((*game)->mlx,
			"textures/wall.xpm", &tail_size, &tail_size);
	(*game)->textures.empty_space = mlx_xpm_file_to_image((*game)->mlx,
			"textures/empty_space.xpm", &tail_size, &tail_size);
	(*game)->textures.collectable = mlx_xpm_file_to_image((*game)->mlx,
			"textures/coin.xpm", &tail_size, &tail_size);
	(*game)->textures.player = mlx_xpm_file_to_image((*game)->mlx,
			"textures/player.xpm", &tail_size, &tail_size);
	(*game)->textures.exit = mlx_xpm_file_to_image((*game)->mlx,
			"textures/exit.xpm", &tail_size, &tail_size);
	(*game)->textures.player_a = mlx_xpm_file_to_image((*game)->mlx,
			"textures/player_left.xpm", &tail_size, &tail_size);
}

int	first_row_norm(int *j, char *map)
{
	while (map[*j] != '\n')
	{
		if (map[*j] != '1')
			return (0);
		(*j)++;
	}
	return (1);
}
