/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:20:56 by aagharbi          #+#    #+#             */
/*   Updated: 2025/04/04 13:56:09 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		kill(data->philos[i].pid, SIGKILL);
		i++;
	}
}

void	*check_death(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (1)
	{
		if (get_time() - philo->last_meal > philo->data->time_to_die)
		{
			sem_wait(philo->data->last_print);
			printf("%lld %d died\n", get_time() - philo->data->start_time,
				philo->id);
			sem_post(philo->data->death);
			exit(0);
		}
	}
}

void	philosopher_routine(t_philo *philo)
{
	pthread_create(&philo->data->thread_monitor, NULL, check_death, philo);
	if (philo->id % 2 == 0)
		usleep(500);
	while (1)
	{
		print_action(philo, "is thinking");
		usleep(1000);
		take_forks(philo);
		if (philo->data->num_philos == 1)
		{
			drop_forks(philo);
			break ;
		}
		print_action(philo, "is eating");
		set_last_meal(philo);
		usleep(philo->data->time_to_eat * 1000);
		drop_forks(philo);
		if (philo->meals_eaten >= philo->data->num_meals
			&& philo->data->num_meals > 0)
			exit((sem_post(philo->data->lock), 0));
		print_action(philo, "is sleeping");
		usleep(philo->data->time_to_sleep * 1000);
	}
	exit(0);
}

void	wait_process(t_data *data)
{
	sem_wait(data->death);
	kill_philos(data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	if (argc < 5 || argc > 6)
		return (printf("Argument Error\n"), 1);
	if (init_data(&data, argv, argc))
		return (printf("Error\n"), 1);
	init_philosophers(&data);
	data.start_time = get_time();
	while (i < data.num_philos)
	{
		data.philos[i].pid = fork();
		if (data.philos[i].pid == 0)
		{
			philosopher_routine(&data.philos[i]);
			exit(0);
		}
		i++;
	}
	pthread_create(&data.monitor, NULL, freez, &data);
	wait_process(&data);
	clean_up(&data);
	return (0);
}
