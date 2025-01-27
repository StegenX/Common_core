/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:17:32 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/20 18:18:29 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	no_collectables(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	no_player(char **map)
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
			if (map[i][j] == 'P')
				counter++;
			j++;
		}
		i++;
	}
	if (counter == 1)
		return (1);
	return (0);
}

int	no_exit(char **map)
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
			if (map[i][j] == 'E')
				counter++;
			j++;
		}
		i++;
	}
	if (counter == 1)
		return (1);
	return (0);
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

int	valid_map(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!first_row_norm(&j, map[0]))
		return (0);
	while (i < game->map.rows - 1)
	{
		if (map[i][0] != '1' || map[i][j - 1] != '1')
			return (0);
		i++;
	}
	if (!map[i])
		return (0);
	j = 0;
	while (map[i][j] && map[i][j] != '\n')
	{
		if (map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}
