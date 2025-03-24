/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stegen <stegen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:57:47 by stegen            #+#    #+#             */
/*   Updated: 2025/03/20 16:58:04 by stegen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_condition(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->mutex.check_con);
    if (((philo->meals_eaten >= philo->data->num_meals) && philo->data->num_meals != -1))
    {
        pthread_mutex_unlock(&philo->data->mutex.check_con);
        return 1;
    }
     pthread_mutex_unlock(&philo->data->mutex.check_con);
    return 0;
}
int check_condition2(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->mutex.check_con2);
    if (philo->data->num_meals == -1 || philo->data->num_meals > 0)
    {
        pthread_mutex_unlock(&philo->data->mutex.check_con2);
        return 1;
    }
    pthread_mutex_unlock(&philo->data->mutex.check_con2);
    return 0;
}

int check_philos(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->mutex.philo);
    if (philo->data->num_philos == 1)
    {
        pthread_mutex_unlock(&philo->data->mutex.philo);
        return 1;
    }
    pthread_mutex_unlock(&philo->data->mutex.philo);
    return 0;
}

int check_for_monitoring(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->mutex.monitor);
    if (((philo->eaten_monitoring >= philo->data->meals_monitoring) && philo->data->meals_monitoring != -1))
    {
        pthread_mutex_unlock(&philo->data->mutex.monitor);
        return 1;
    }
     pthread_mutex_unlock(&philo->data->mutex.monitor);
    return 0;
}