/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:21:12 by aagharbi          #+#    #+#             */
/*   Updated: 2025/04/04 14:21:15 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <fcntl.h>

int	init_data(t_data *data, char **argv, int ac)
{
	data->num_philos = ft_atoi(argv[1], data);
	data->time_to_die = ft_atoi(argv[2], data);
	data->time_to_eat = ft_atoi(argv[3], data);
	data->time_to_sleep = ft_atoi(argv[4], data);
	if (ac == 6)
		data->num_meals = ft_atoi(argv[5], data);
	else
	{
		data->num_meals = -1;
	}
	if (data->negative_value == 1 || data->num_philos == 0)
		return (1);
	sem_unlink("/forks");
	data->forks = sem_open("/forks", O_CREAT | O_EXCL, 0644, data->num_philos);
	if (data->forks == SEM_FAILED)
	{
		perror("sem_open forks");
		return (1);
	}
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos || init_norm(data))
		return (1);
	return (0);
}

void	init_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal = get_time();
		data->philos[i].data = data;
		i++;
	}
}

int	init_norm(t_data *data)
{
	sem_unlink("/death");
	sem_unlink("/last_print");
	sem_unlink("/lock");
	data->death = sem_open("/death", O_CREAT, 0644, 0);
	data->last_print = sem_open("/last_print", O_CREAT, 0644, 1);
	data->lock = sem_open("/lock", O_CREAT, 0644, 0);
	return (0);
}
