/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stegen <stegen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:21:06 by aagharbi          #+#    #+#             */
/*   Updated: 2025/03/30 01:29:05 by stegen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_up(t_data *data)
{
	sem_close(data->forks);
    sem_unlink("/forks");

    sem_close(data->print_lock);
    sem_unlink("/print_lock");

    sem_close(data->sim_end);
    sem_unlink("/sim_end_lock");
	free(data->philos);
}

int	is_simulation_running(t_data *data)
{
	int	running;

	sem_wait(data->sim_end);
	running = data->simulation_end;
	sem_post(data->sim_end);
	return (running);
}

// void set_simulation_end(t_data *data)
// {
//     sem_wait(data->sim_end);
//     data->simulation_end = 1;
//     sem_post(data->sim_end);
// }

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
