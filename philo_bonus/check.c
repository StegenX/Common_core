/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stegen <stegen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:57:47 by stegen            #+#    #+#             */
/*   Updated: 2025/03/30 01:27:44 by stegen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_condition(t_philo *philo)
{
    sem_wait(philo->data->check_con);  // Wait for access to the semaphore
    if ((philo->meals_eaten >= philo->data->num_meals) && philo->data->num_meals != -1)
    {
        sem_post(philo->data->check_con);  // Release access to the semaphore
        return 1;
    }
    sem_post(philo->data->check_con);  // Release access to the semaphore
    return 0;
}

int check_condition2(t_philo *philo)
{
    sem_wait(philo->data->check_con2);  // Wait for access to the semaphore
    if (philo->data->num_meals == -1 || philo->data->num_meals > 0)
    {
        sem_post(philo->data->check_con2);  // Release access to the semaphore
        return 1;
    }
    sem_post(philo->data->check_con2);  // Release access to the semaphore
    return 0;
}

int check_philos(t_philo *philo)
{
    sem_wait(philo->data->philo_lock);  // Wait for access to the semaphore
    if (philo->data->num_philos == 1)
    {
        sem_post(philo->data->philo_lock);  // Release access to the semaphore
        return 1;
    }
    sem_post(philo->data->philo_lock);  // Release access to the semaphore
    return 0;
}

int check_for_monitoring(t_philo *philo)
{
    sem_wait(philo->data->monitor_lock);  // Wait for access to the semaphore
    if ((philo->eaten_monitoring >= philo->data->meals_monitoring) && philo->data->meals_monitoring != -1)
    {
        sem_post(philo->data->monitor_lock);  // Release access to the semaphore
        return 1;
    }
    sem_post(philo->data->monitor_lock);  // Release access to the semaphore
    return 0;
}