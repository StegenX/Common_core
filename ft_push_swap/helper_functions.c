/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:08:54 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/06 09:12:30 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(char **av)
{
	int	i;
	int	zero;

	i = 1;
	zero = 0;
	while (av[i])
	{
		if (!arg_is_num(av[i]))
			return (0);
		if (arg_is_zero(av[i]))
			zero++;
		i++;
	}
	if (zero > 1)
		return (0);
	return (1);
}

int	arg_is_num(char *av)
{
	int	i;

	i = 0;
	if ((av[i] == '+' || av[i] == '-'))
		i++;
	while ((av[i] && (av[i] >= '0' && av[i] <= '9')) || av[i] == ' ')
		i++;
	if ((av[i] == '+' || av[i] == '-')
		&& (av[i + 1] >= '0' && av[i + 1] <= '9'))
		i++;
	if (av[i] != '\0' && !(av[i] >= '0' && av[i] <= '9'))
		return (0);
	return (1);
}

int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '+' || av[i] == '-')
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}
