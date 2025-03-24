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
    philo->eaten_monitoring++;
    pthread_mutex_unlock(&philo->data->mutex.lock_meal);
}