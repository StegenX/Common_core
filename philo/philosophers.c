/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:20:56 by aagharbi          #+#    #+#             */
/*   Updated: 2025/04/02 08:36:22 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_joining(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(500);
	while (!is_simulation_end(philo->data))
	{
		print_action(philo, "is thinking");
		usleep(500);
		take_forks(philo);
		if (is_simulation_end(philo->data) || check_philos(philo))
		{
			drop_forks(philo);
			break ;
		}
		print_action(philo, "is eating");
		set_last_meal(philo);
		usleep(philo->data->time_to_eat * 1000);
		drop_forks(philo);
		if (is_simulation_end(philo->data) || check_condition(philo))
			break ;
		print_action(philo, "is sleeping");
		usleep(philo->data->time_to_sleep * 1000);
	}
	return (NULL);
}

void	*monitor_philosophers(void *arg)
{
	int			i;
	long long	last;
	t_data		*data;

	data = (t_data *)arg;
	while (!is_simulation_end(data))
	{
		i = 0;
		while (i < data->num_philos)
		{
			last = get_last_meal(&data->philos[i]);
			if ((get_time() - last) > data->time_to_die)
			{
				set_simulation_end(data);
				if (check_for_monitoring(&data->philos[i]))
					return (NULL);
				printf("%lld %d died\n", get_time() - data->start_time,
					data->philos[i].id);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	data.negative_value = 0;
	if (argc < 5 || argc > 6)
		return (printf("Argument Error\n"), 1);
	if (init_data(&data, argv, argc))
		return (printf("Error\n"), 1);
	init_philosophers(&data);
	data.start_time = get_time();
	while (i < data.num_philos)
	{
		pthread_create(&data.philos[i].thread, NULL, philosopher_routine,
			&data.philos[i]);
		i++;
	}
	pthread_create(&data.thread_monitor, NULL, monitor_philosophers, &data);
	pthread_join(data.thread_monitor, NULL);
	set_joining(&data);
	clean_up(&data);
	return (0);
}
