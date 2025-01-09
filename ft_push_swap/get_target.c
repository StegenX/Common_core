/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:10:29 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/06 09:43:58 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target(t_stacks **stack, int b_index,
		int targ_i, int target_p)
{
	t_stacks	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->i > b_index && tmp->i < targ_i)
		{
			targ_i = tmp->i;
			target_p = tmp->p;
		}
		tmp = tmp->next;
	}
	if (targ_i != INT_MAX)
		return (target_p);
	tmp = *stack;
	while (tmp)
	{
		if (tmp->i < targ_i)
		{
			targ_i = tmp->i;
			target_p = tmp->p;
		}
		tmp = tmp->next;
	}
	return (target_p);
}

void	get_pos(t_stacks **stack)
{
	t_stacks	*s;
	int			i;

	s = *stack;
	i = 0;
	while (s)
	{
		s->p = i;
		s = s->next;
		i++;
	}
}

int	abs_nb(int cost)
{
	if (cost < 0)
		return (cost * -1);
	return (cost);
}

t_stacks	*lst_beforelast(t_stacks *stack)
{
	while (stack && stack->next->next)
		stack = stack->next;
	return (stack);
}
