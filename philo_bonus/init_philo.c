/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stegen <stegen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:21:12 by aagharbi          #+#    #+#             */
/*   Updated: 2025/03/30 01:36:22 by stegen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <fcntl.h> // Required for O_CREAT and O_EXCL

int	init_data(t_data *data, char **argv, int ac)
{
    data->num_philos = atoi(argv[1]);
    data->time_to_die = atoi(argv[2]);
    data->time_to_eat = atoi(argv[3]);
    data->time_to_sleep = atoi(argv[4]);
    if (ac == 6)
        data->num_meals = atoi(argv[5]);
    else
        data->num_meals = -1;
    data->simulation_end = 0;
    data->meals_monitoring = data->num_meals;

    // Initialize the semaphore for forks
	sem_unlink("/forks");  // Unlink any existing semaphore with the same name
	data->forks = sem_open("/forks", O_CREAT | O_EXCL, 0644, data->num_philos);
	if (data->forks == SEM_FAILED)
	{
		perror("sem_open forks");
		return (1);
	}

    // Allocate memory for philosophers
    data->philos = malloc(sizeof(t_philo) * data->num_philos);
    if (!data->philos)
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
        data->philos[i].eaten_monitoring = 0;
        data->philos[i].last_meal = get_time();
        data->philos[i].data = data;
        i++;
    }
}

void	init_norm(t_data *data)
{
    // Initialize the semaphore for printing
    data->print_lock = sem_open("/print_lock", O_CREAT | O_EXCL, 0644, 1);
    if (data->print_lock == SEM_FAILED)
    {
        perror("sem_open print_lock");
        exit(1); // Exit the program if semaphore initialization fails
    }

    // Initialize the semaphore for simulation_end
    data->sim_end = sem_open("/sim_end_lock", O_CREAT | O_EXCL, 0644, 1);
    if (data->sim_end == SEM_FAILED)
    {
        perror("sem_open sim_end");
        exit(1); // Exit the program if semaphore initialization fails
    }
}
