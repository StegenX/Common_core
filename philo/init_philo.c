/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:21:12 by aagharbi          #+#    #+#             */
/*   Updated: 2025/03/05 17:25:29 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, char **argv, int ac)
{
	int	i;

	i = 0;
	data->num_philos = atoi(argv[1]);
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	if (ac == 6)
		data->num_meals = atoi(argv[5]);
	else
		data->num_meals = -1;
	data->simulation_end = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->forks || !data->philos)
		return (1);
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	init_norm(data);
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
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->num_philos];
		data->philos[i].data = data;
		i++;
	}
}

void	init_norm(t_data *data)
{
	pthread_mutex_init(&data->sim_end, NULL);
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->lock_meal, NULL);
	pthread_mutex_init(&data->print_lock, NULL);
}
