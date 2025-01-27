/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:21:05 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/20 18:22:00 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y, t_flood_fill *f)
{
	if (x < 0 || y < 0 || x >= f->j || y >= f->i)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		f->collectibles++;
	if (map[y][x] == 'E')
		f->exit = 1;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, f);
	flood_fill(map, x - 1, y, f);
	flood_fill(map, x, y + 1, f);
	flood_fill(map, x, y - 1, f);
}

int	count_collectables(char **map)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	j = 0;
	counter = 0;
	while (map[i][j])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] == 'C')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

int	valid_path(char **map)
{
	t_flood_fill	f;

	f.i = 0;
	f.j = 0;
	f.counter = count_collectables(map);
	f.x = 0;
	f.y = 0;
	f.exit = 0;
	f.collectibles = 0;
	while (map[f.i])
		f.i++;
	while (map[0][f.j] != '\n')
		f.j++;
	get_player_position(map, &f.x, &f.y);
	flood_fill(map, f.x, f.y, &f);
	if (f.counter == f.collectibles && f.exit == 1)
		return (1);
	return (0);
}

int	check_map_rules(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'K')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (ft_len(map[i]) != ft_len(map[0]))
			return (0);
		i++;
	}
	return (1);
}
