/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:20:56 by aagharbi          #+#    #+#             */
/*   Updated: 2025/03/13 18:07:30 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(500);
	while (!is_simulation_running(philo->data))
	{
		// if (is_simulation_running(philo->data))
		// 	break ;
		print_action(philo, "is thinking");
		usleep(500);
		take_forks(philo);
		if (is_simulation_running(philo->data) || philo->data->num_philos == 1)
		{
			drop_forks(philo);
			break ;
		}
		print_action(philo, "is eating");
		// pthread_mutex_lock(&philo->data->meals);
		// philo->meals_eaten++;
		// pthread_mutex_unlock(&philo->data->meals);
		pthread_mutex_lock(&philo->data->lock_meal);
		philo->last_meal = get_time();
		pthread_mutex_unlock(&philo->data->lock_meal);
		usleep(philo->data->time_to_eat * 1000);
		drop_forks(philo);
		if (is_simulation_running(philo->data))
			break ;
		print_action(philo, "is sleeping");
		usleep(philo->data->time_to_sleep * 1000);
	}
	return (NULL);
}

void	monitor_philosophers(t_data *data)
{
	int			i;
	long long	last;
	// int meals;
	// t_data	*data;

	// data = (t_data *)arg;

	while (!is_simulation_running(data))
	{
		i = 0;
		while (i < data->num_philos)
		{
			pthread_mutex_lock(&data->sim_end);
			pthread_mutex_lock(&data->lock_meal);
			last = data->philos[i].last_meal;
			pthread_mutex_unlock(&data->lock_meal);
			// pthread_mutex_lock(&data->meals);
			// meals = data->time_to_die;
			// pthread_mutex_unlock(&data->meals);
			if ((get_time() - last) > data->time_to_die)
			{
				data->simulation_end = 1;
				printf("%lld %d died\n", get_time() - data->start_time,
					data->philos[i].id);
				pthread_mutex_unlock(&data->sim_end);
				return ;
			}
			pthread_mutex_unlock(&data->sim_end);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	if (argc < 5 || argc > 6)
		return (printf("Argement Error"), 1);
	if (init_data(&data, argv, argc))
		return (printf("Error: Memory allocation failed\n"), 1);
	init_philosophers(&data);
	data.start_time = get_time();
	while (i < data.num_philos)
	{
		pthread_create(&data.philos[i].thread, NULL, philosopher_routine,
			&data.philos[i]);
		i++;
	}
	// pthread_create(&data.thread_monitor, NULL, monitor_philosophers,
	// 	&data);
	// pthread_join(data.thread_monitor, NULL);
	i = 0;
	while (i < data.num_philos)
	{
		pthread_join(data.philos[i].thread, NULL);
		i++;
	}
	monitor_philosophers(&data);
	clean_up(&data);
	return (0);
}
