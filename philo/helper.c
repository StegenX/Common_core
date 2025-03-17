/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:21:06 by aagharbi          #+#    #+#             */
/*   Updated: 2025/03/13 17:41:43 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_up(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->mutex.print_lock);
	// pthread_mutex_destroy(&data->meals);
	pthread_mutex_destroy(&data->mutex.sim_end);
	pthread_mutex_destroy(&data->mutex.lock);
	pthread_mutex_destroy(&data->mutex.lock_meal);
	pthread_mutex_destroy(&data->mutex.check_sim);
	pthread_mutex_destroy(&data->mutex.monitor_lock);
	free(data->forks);
	free(data->philos);
}

int	is_simulation_running(t_data *data)
{
	int	running;

	pthread_mutex_lock(&data->mutex.check_sim);
	running = data->simulation_end;
	pthread_mutex_unlock(&data->mutex.check_sim);
	return (running);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
