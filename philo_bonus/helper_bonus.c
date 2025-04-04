/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:21:06 by aagharbi          #+#    #+#             */
/*   Updated: 2025/04/04 14:21:57 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_up(t_data *data)
{
	sem_close(data->forks);
	sem_unlink("/forks");
	sem_close(data->death);
	sem_unlink("/death");
	sem_close(data->last_print);
	sem_unlink("/last_print");
	free(data->philos);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	*freez(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = 0;
	while (i++ < data->num_philos)
		sem_wait(data->lock);
	sem_post(data->death);
	return (NULL);
}

long long	ft_atoi(const char *nptr, t_data *my_data)
{
	long long	nb;

	nb = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr++ == '-')
			my_data->negative_value = 1;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		nb = nb * 10 + (*nptr - 48);
		nptr++;
	}
	if (*nptr)
		exit((printf("ERROR\n"), 1));
	return (nb);
}
