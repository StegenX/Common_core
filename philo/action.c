/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:21:09 by aagharbi          #+#    #+#             */
/*   Updated: 2025/04/02 08:23:15 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex.lock);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_unlock(&philo->data->mutex.lock);
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		if (philo->data->num_philos == 1)
		{
			pthread_mutex_unlock(&philo->data->mutex.lock);
			return ;
		}
		pthread_mutex_unlock(&philo->data->mutex.lock);
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
	}
}

void	print_action(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->data->mutex.print_lock);
	pthread_mutex_lock(&philo->data->mutex.sim_end);
	if (!philo->data->simulation_end)
		printf("%lld %d %s\n", get_time() - philo->data->start_time, philo->id,
			action);
	pthread_mutex_unlock(&philo->data->mutex.sim_end);
	pthread_mutex_unlock(&philo->data->mutex.print_lock);
}

void	drop_forks(t_philo *philo)
{
	if (philo->data->num_philos == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
