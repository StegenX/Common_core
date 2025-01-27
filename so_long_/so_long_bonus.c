/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:52:00 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/21 11:52:02 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game **game)
{
	int	i;

	i = 0;
	while ((*game)->map.map[i])
	{
		free((*game)->map.map[i]);
		i++;
	}
	free((*game)->map.map);
	mlx_destroy_image((*game)->mlx, (*game)->textures.collectable);
	mlx_destroy_image((*game)->mlx, (*game)->textures.empty_space);
	mlx_destroy_image((*game)->mlx, (*game)->textures.player);
	mlx_destroy_image((*game)->mlx, (*game)->textures.player_a);
	mlx_destroy_image((*game)->mlx, (*game)->textures.enemy_animation1);
	mlx_destroy_image((*game)->mlx, (*game)->textures.enemy_animation2);
	mlx_destroy_image((*game)->mlx, (*game)->textures.exit);
	mlx_destroy_image((*game)->mlx, (*game)->textures.wall);
	mlx_clear_window((*game)->mlx, (*game)->window);
	mlx_destroy_window((*game)->mlx, (*game)->window);
	mlx_destroy_display((*game)->mlx);
	free((*game)->mlx);
	free(*game);
	exit(0);
	return (0);
}

int	check_valid(t_game *game, char *file)
{
	int		i;
	int		j;
	char	**map;

	i = 1;
	j = 0;
	map = read_map(file, game->map.rows);
	if (!*map)
		return (ft_free(map), 0);
	if (!check_map(map) || !valid_map(map, game) || !check_map_rules(map)
		|| !no_collectables(map) || !no_exit(map) || !no_player(map)
		|| !no_enemy(map) || !valid_path(map))
		return (ft_free(map), 0);
	return (ft_free(map), 1);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->width = 800;
	game->hight = 800;
	game->frame_counter = 0;
	game->keycode = 0;
	if (ac != 2)
		exit((free(game), ft_putstr_fd("Error\nInvalid Map\n", 2), 1));
	game->map.rows = count_rows(av[1]);
	if (!check_valid(game, av[1]))
		exit((free(game), ft_putstr_fd("Error\nInvalid Map\n", 2), 1));
	game->map.rows = count_rows(av[1]);
	game->map.map = read_map(av[1], game->map.rows);
	game->map.columns = count_columns(game->map.map[0]);
	player_position(&game->map, &game->player.player_x, &game->player.player_y);
	init_window(32, &game);
	init_textures(32, &game);
	put_image_in_window(&game, game->keycode);
	mlx_key_hook(game->window, key_press, &game);
	mlx_hook(game->window, 17, 0, exit_game, &game);
	game->frame_slower = 0;
	mlx_loop_hook(game->mlx, (void *)game_loop, &game);
	mlx_loop(game->mlx);
	return (0);
}
