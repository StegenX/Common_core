#include "philo.h"

int	is_simulation_end(t_data *data)
{
    int	end;

    sem_wait(data->sim_end);  // Wait for access to the simulation_end flag
    end = data->simulation_end;
    sem_post(data->sim_end);  // Release access to the simulation_end flag
    return (end);
}

void	set_simulation_end(t_data *data)
{
    sem_wait(data->sim_end);  // Wait for access to the simulation_end flag
    data->simulation_end = 1;
    sem_post(data->sim_end);  // Release access to the simulation_end flag
}

long long	get_last_meal(t_philo *philo)
{
    long long	last_meal;

    sem_wait(philo->data->lock_meal);  // Wait for access to the last_meal field
    last_meal = philo->last_meal;
    sem_post(philo->data->lock_meal);  // Release access to the last_meal field
    return (last_meal);
}

void	set_last_meal(t_philo *philo)
{
    sem_wait(philo->data->lock_meal);  // Wait for access to the last_meal field
    philo->last_meal = get_time();
    philo->meals_eaten++;
    philo->eaten_monitoring++;
    sem_post(philo->data->lock_meal);  // Release access to the last_meal field
}