/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:21:06 by aagharbi          #+#    #+#             */
/*   Updated: 2025/04/02 08:25:54 by aagharbi         ###   ########.fr       */
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
	pthread_mutex_destroy(&data->mutex.sim_end);
	pthread_mutex_destroy(&data->mutex.lock);
	pthread_mutex_destroy(&data->mutex.lock_meal);
	pthread_mutex_destroy(&data->mutex.check_sim);
	pthread_mutex_destroy(&data->mutex.monitor_lock);
	pthread_mutex_destroy(&data->mutex.monitor);
	pthread_mutex_destroy(&data->mutex.check_con);
	pthread_mutex_destroy(&data->mutex.check_con2);
	pthread_mutex_destroy(&data->mutex.check_philo);
	pthread_mutex_destroy(&data->mutex.philo);
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

int	ft_atoi(const char *nptr, t_data *my_data)
{
	int	nb;

	nb = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr++ == '-')
			my_data->negative_value = 1;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		nb = nb * 10 + (*nptr - 48);
		nptr++;
	}
	return (nb);
}
