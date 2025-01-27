/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:40:02 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/20 18:42:59 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game **game)
{
	(*game)->keycode = keycode;
	if (keycode == 65307)
		exit_game(game);
	if (keycode == 'w')
		move_player(game, 0, -1, keycode);
	else if (keycode == 'a')
		move_player(game, -1, 0, keycode);
	else if (keycode == 's')
		move_player(game, 0, 1, keycode);
	else if (keycode == 'd')
		move_player(game, 1, 0, keycode);
	return (0);
}

void	move_player(t_game **game, int dx, int dy, int keycode)
{
	int	new_x;
	int	new_y;

	new_x = (*game)->player.player_x + dx;
	new_y = (*game)->player.player_y + dy;
	if ((*game)->map.map[new_y][new_x] == 'E')
	{
		if (no_collectable_left(game))
			exit_game(game);
		(*game)->map.map[new_y - dy][new_x - dx] = '0';
		(*game)->player.player_x = new_x;
		(*game)->player.player_y = new_y;
		(*game)->player.moves++;
		ft_putnbr_fd((*game)->player.moves, 1);
		write(1, "\n", 1);
		put_image_in_window(game, keycode);
	}
	else if ((*game)->map.map[new_y][new_x] == '0'
		|| (*game)->map.map[new_y][new_x] == 'C')
		if_empty_space_(game, new_x, new_y, keycode);
}

void	game_loop(t_game **game)
{
	(*game)->frame_slower++;
	if ((*game)->frame_slower == 500)
	{
		(*game)->frame_counter++;
		(*game)->frame_slower = 0;
	}
	if ((*game)->frame_counter >= 2)
		(*game)->frame_counter = 0;
	put_image_in_window(game, (*game)->keycode);
}

int	nrm_loop(t_game **game, int x[3], int rows, int columns)
{
	if ((*game)->map.map[rows][columns] == 'E')
	{
		mlx_put_image_to_window((*game)->mlx, (*game)->window,
			(*game)->textures.exit, x[0], x[1]);
		return (1);
	}
	else if ((*game)->map.map[rows][columns] == 'P')
	{
		if (x[2] == 0)
			mlx_put_image_to_window((*game)->mlx, (*game)->window,
				(*game)->textures.player, x[0], x[1]);
		else if (x[2] == 1)
			mlx_put_image_to_window((*game)->mlx, (*game)->window,
				(*game)->textures.player_a, x[0], x[1]);
		return (1);
	}
	return (0);
}
