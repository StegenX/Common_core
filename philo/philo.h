/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:21:17 by aagharbi          #+#    #+#             */
/*   Updated: 2025/03/17 18:01:06 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	// int 			eaten_monitoring;
	long long		last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
	pthread_t		thread;
}					t_philo;

typedef struct s_mutex
{
	pthread_mutex_t	meals;
	pthread_mutex_t	sim_end;
	pthread_mutex_t	lock;
	pthread_mutex_t	lock_meal;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	monitor_lock;
	pthread_mutex_t	check_sim;
	pthread_mutex_t	check_con;
	pthread_mutex_t	check_con2;
	pthread_mutex_t	check_philo;
	pthread_mutex_t	monitor;
	pthread_mutex_t	philo;
}	t_mutex;

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	// int				meals_monitoring;
	long long		start_time;
	int				simulation_end;
	t_philo			*philos;
	t_mutex			mutex;
	pthread_mutex_t	*forks;
	pthread_t		thread_monitor;
}					t_data;

long long			get_time(void);
void				print_action(t_philo *philo, char *action);
int					init_data(t_data *data, char **argv, int ac);
void				init_philosophers(t_data *data);
void				*philosopher_routine(void *arg);
void	*monitor_philosophers(void *arg);
void				clean_up(t_data *data);
void				drop_forks(t_philo *philo);
int					is_simulation_running(t_data *data);
void				init_norm(t_data *data);
void				take_forks(t_philo *philo);

#endif
