/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:25:19 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/20 18:29:59 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	get_player_position(char **map, int *x, int *y)
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
			if (map[i][j] == 'P')
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

int	count_rows(char *file)
{
	int		count;
	int		fd;
	char	buffer[1];

	count = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, buffer, 1) > 0)
	{
		if (buffer[0] == '\n')
			count++;
	}
	return (count + 1);
}

int	no_collectable_left(t_game **game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (*game)->map.rows)
	{
		j = 0;
		while (j < (*game)->map.columns)
		{
			if ((*game)->map.map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	count_columns(char *columns)
{
	int	i;

	i = 0;
	while (columns[i] != '\n')
	{
		i++;
	}
	return (i);
}
