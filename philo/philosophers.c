/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:20:56 by aagharbi          #+#    #+#             */
/*   Updated: 2025/03/05 17:20:57 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(5000);
	while (is_simulation_running(philo->data))
	{
		print_action(philo, "is thinking");
		usleep(1000);
		take_forks(philo);
		print_action(philo, "is eating");
		pthread_mutex_lock(&philo->data->lock_meal);
		philo->last_meal = get_time();
		pthread_mutex_unlock(&philo->data->lock_meal);
		usleep(philo->data->time_to_eat * 1000);
		drop_forks(philo);
		print_action(philo, "is sleeping");
		usleep(philo->data->time_to_sleep * 1000);
	}
	return (NULL);
}

void	monitor_philosophers(t_data *data)
{
	int			i;
	long long	last;

	while (is_simulation_running(data))
	{
		i = 0;
		while (i < data->num_philos)
		{
			pthread_mutex_lock(&data->sim_end);
			pthread_mutex_lock(&data->lock_meal);
			last = data->philos[i].last_meal;
			pthread_mutex_unlock(&data->lock_meal);
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
		usleep(5000);
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
	monitor_philosophers(&data);
	i = 0;
	while (i < data.num_philos)
	{
		pthread_join(data.philos[i].thread, NULL);
		i++;
	}
	clean_up(&data);
	return (0);
}
