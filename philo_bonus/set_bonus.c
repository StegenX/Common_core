/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:57:21 by aagharbi          #+#    #+#             */
/*   Updated: 2025/04/04 13:57:22 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_last_meal(t_philo *philo)
{
	long long	last_meal;

	last_meal = philo->last_meal;
	return (last_meal);
}

void	set_last_meal(t_philo *philo)
{
	philo->last_meal = get_time();
	philo->meals_eaten++;
}
