#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
    int             id;
    int             meals_eaten;
    long long       last_meal;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    struct s_data   *data;
    pthread_t       thread;
} t_philo;

typedef struct s_data
{
    int             num_philos;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             num_meals;
    long long       start_time;
    int             simulation_end;
    pthread_mutex_t print_lock;
    pthread_mutex_t *forks;
    t_philo         *philos;
} t_data;

// Utils
long long   get_time(void);
void        print_action(t_philo *philo, char *action);

// Initialization
int         init_data(t_data *data, char **argv, int ac);
void        init_philosophers(t_data *data);

// Simulation
void        *philosopher_routine(void *arg);
void        start_simulation(t_data *data);

// Monitoring
void        monitor_philosophers(t_data *data);

// Cleanup
void        clean_up(t_data *data);

#endif
