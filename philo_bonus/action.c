/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stegen <stegen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:21:09 by aagharbi          #+#    #+#             */
/*   Updated: 2025/03/30 01:24:28 by stegen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
    sem_wait(philo->data->forks);  // Take one fork
    sem_wait(philo->data->forks);  // Take another fork
    print_action(philo, "has taken a fork");
}

void	print_action(t_philo *philo, char *action)
{
    sem_wait(philo->data->print_lock);  // Wait for access to the print semaphore
    sem_wait(philo->data->sim_end);  // Protect access to simulation_end
    if (!philo->data->simulation_end)
        printf("%lld %d %s\n", get_time() - philo->data->start_time, philo->id, action);
    sem_post(philo->data->sim_end);  // Release access to simulation_end
    sem_post(philo->data->print_lock);  // Release access to the print semaphore
}

void	drop_forks(t_philo *philo)
{
    sem_post(philo->data->forks);  // Release one fork
    sem_post(philo->data->forks);  // Release another fork
}
