/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stegen <stegen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:20:56 by aagharbi          #+#    #+#             */
/*   Updated: 2025/03/17 08:09:19 by stegen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_simulation_end(t_data *data)
{
    int	end;

    pthread_mutex_lock(&data->mutex.sim_end);
    end = data->simulation_end;
    pthread_mutex_unlock(&data->mutex.sim_end);
    return (end);
}

void	set_simulation_end(t_data *data)
{
    pthread_mutex_lock(&data->mutex.sim_end);
    data->simulation_end = 1;
    pthread_mutex_unlock(&data->mutex.sim_end);
}

long long	get_last_meal(t_philo *philo)
{
    long long	last_meal;

    pthread_mutex_lock(&philo->data->mutex.lock_meal);
    last_meal = philo->last_meal;
    pthread_mutex_unlock(&philo->data->mutex.lock_meal);
    return (last_meal);
}

void	set_last_meal(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->mutex.lock_meal);
    philo->last_meal = get_time();
	philo->meals_eaten++;
    pthread_mutex_unlock(&philo->data->mutex.lock_meal);
}

void	*philosopher_routine(void *arg)
{
    t_philo	*philo;

    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
        usleep(500);
    while (!is_simulation_end(philo->data) && (philo->data->num_meals == -1 || philo->data->num_meals > 0))
    {
        print_action(philo, "is thinking");
        usleep(500);
        take_forks(philo);
        if (is_simulation_end(philo->data) || philo->data->num_philos == 1 || philo->data->num_meals == 0)
        {
            drop_forks(philo);
            break ;
        }
        print_action(philo, "is eating");
        set_last_meal(philo);
        usleep(philo->data->time_to_eat * 1000);
        drop_forks(philo);
        if (is_simulation_end(philo->data) || philo->data->num_meals == 0)	
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
                printf("%lld %d died\n", get_time() - data->start_time,
                    data->philos[i].id);
                return (NULL);
            }
			else if (data->num_meals != -1 && data->philos[i].meals_eaten >= data->num_meals)
			{
				pthread_mutex_lock(&data->mutex.monitor_lock);
				data->num_meals--;
				pthread_mutex_unlock(&data->mutex.monitor_lock);
			}	
            i++;
        }
        usleep(500);
    }
    return (NULL);
}

int	main(int argc, char **argv)
{
    t_data	data;
    int		i;

    i = 0;
    if (argc < 5 || argc > 6)
        return (printf("Argument Error\n"), 1);
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
    pthread_create(&data.thread_monitor, NULL, monitor_philosophers, &data);
    pthread_join(data.thread_monitor, NULL);
    i = 0;
    while (i < data.num_philos)
    {
        pthread_join(data.philos[i].thread, NULL);
        i++;
    }
    clean_up(&data);
    return (0);
}
