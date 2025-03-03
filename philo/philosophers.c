#include "philo.h"

long long get_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000); // Convert to milliseconds
}

void print_action(t_philo *philo, char *action)
{
    pthread_mutex_lock(&philo->data->print_lock);
    if (!philo->data->simulation_end)
        printf("[%lld] Philosopher %d %s\n", get_time() - philo->data->start_time, philo->id, action);
    pthread_mutex_unlock(&philo->data->print_lock);
}

int init_data(t_data *data, char **argv, int ac)
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
    data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
    data->philos = malloc(sizeof(t_philo) * data->num_philos);
    if (!data->forks || !data->philos)
        return (1);
    int i = 0;
    while (i < data->num_philos)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    pthread_mutex_init(&data->print_lock, NULL);
    return (0);
}

void init_philosophers(t_data *data)
{
    int i = 0;
    while (i < data->num_philos)
    {
        data->philos[i].id = i + 1;
        data->philos[i].meals_eaten = 0;
        data->philos[i].last_meal = get_time();
        data->philos[i].left_fork = &data->forks[i];
        data->philos[i].right_fork = &data->forks[(i + 1) % data->num_philos];
        data->philos[i].data = data;
        i++;
    }
}

void take_forks(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(philo->right_fork);
        print_action(philo, "has taken a fork");
        pthread_mutex_lock(philo->left_fork);
    }
    else
    {
        pthread_mutex_lock(philo->left_fork);
        print_action(philo, "has taken a fork");
        pthread_mutex_lock(philo->right_fork);
    }
}

void drop_forks(t_philo *philo)
{
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}

void *philosopher_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    if (philo->id % 2 == 0)
        usleep(1000);

    while (!philo->data->simulation_end)
    {
        print_action(philo, "is thinking");

        take_forks(philo);
        print_action(philo, "is eating");

        philo->last_meal = get_time();
        usleep(philo->data->time_to_eat * 1000);

        drop_forks(philo);
        print_action(philo, "is sleeping");
        usleep(philo->data->time_to_sleep * 1000);
    }
    return NULL;
}

void monitor_philosophers(t_data *data)
{
    int i;
    while (!data->simulation_end)
    {   
        i = 0;
        while (i < data->num_philos)
        {
            if (get_time() - data->philos[i].last_meal > data->time_to_die)
            {
                data->simulation_end = 1;
                printf("[%lld] Philosopher %d died\n", get_time() - data->start_time, data->philos[i].id);
                return;
            }
            i++;
        }
        usleep(1000);
    }
}

void clean_up(t_data *data)
{
    int i = 0;
    while (i < data->num_philos)
    {
        pthread_mutex_destroy(&data->forks[i]);
        i++;
    }
    pthread_mutex_destroy(&data->print_lock);
    free(data->forks);
    free(data->philos);
}

int main(int argc, char **argv)
{
    t_data data;
    int i = 0;

    if (argc < 5 || argc > 6)
        return (printf("Argement Error"), 1);
    if (init_data(&data, argv, argc))
        return (printf("Error: Memory allocation failed\n"), 1);

    init_philosophers(&data);
    data.start_time = get_time();
    while (i < data.num_philos)
    {
        pthread_create(&data.philos[i].thread, NULL, philosopher_routine, &data.philos[i]);
        i++;
    }
    monitor_philosophers(&data);
    i = 0;
    while (i < data.num_philos)
    {
        pthread_join(data.philos[i].thread, NULL);
        i++;
    }
    clean_up(&data);
    return (0);
}

