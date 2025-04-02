/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:21:12 by aagharbi          #+#    #+#             */
/*   Updated: 2025/04/02 08:26:30 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, char **argv, int ac)
{
	int	i;

	i = 0;
	data->num_philos = ft_atoi(argv[1], data);
	data->time_to_die = ft_atoi(argv[2], data);
	data->time_to_eat = ft_atoi(argv[3], data);
	data->time_to_sleep = ft_atoi(argv[4], data);
	if (ac == 6)
		data->num_meals = ft_atoi(argv[5], data);
	else
		data->num_meals = -1;
	data->simulation_end = 0;
	data->meals_monitoring = data->num_meals;
	if (data->negative_value || !data->num_philos)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->forks || !data->philos)
		return (1);
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (init_norm(data), 0);
}

void	init_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].eaten_monitoring = 0;
		data->philos[i].last_meal = get_time();
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->num_philos];
		data->philos[i].data = data;
		i++;
	}
}

void	init_norm(t_data *data)
{
	pthread_mutex_init(&data->mutex.sim_end, NULL);
	pthread_mutex_init(&data->mutex.monitor_lock, NULL);
	pthread_mutex_init(&data->mutex.monitor, NULL);
	pthread_mutex_init(&data->mutex.check_sim, NULL);
	pthread_mutex_init(&data->mutex.lock, NULL);
	pthread_mutex_init(&data->mutex.lock_meal, NULL);
	pthread_mutex_init(&data->mutex.print_lock, NULL);
	pthread_mutex_init(&data->mutex.check_con, NULL);
	pthread_mutex_init(&data->mutex.check_con2, NULL);
	pthread_mutex_init(&data->mutex.check_philo, NULL);
	pthread_mutex_init(&data->mutex.philo, NULL);
}
