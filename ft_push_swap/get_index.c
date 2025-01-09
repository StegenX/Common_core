/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:26:06 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/06 09:42:56 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_index(t_stacks *stack_a, int s_size)
{
	t_stacks	*ptr;
	t_stacks	*big;
	int			value;

	while (--s_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		big = NULL;
		while (ptr)
		{
			if (ptr->v == INT_MIN && ptr->i == 0)
				ptr->i = 1;
			if (ptr->v > value && ptr->i == 0)
			{
				value = ptr->v;
				big = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (big != NULL)
			big->i = s_size;
	}
}

int	find_highest_index(t_stacks *stack)
{
	int	index;

	index = stack->i;
	while (stack)
	{
		if (stack->i > index)
			index = stack->i;
		stack = stack->next;
	}
	return (index);
}

int	get_low_index(t_stacks **stack_a)
{
	t_stacks	*tmp;
	int			low_pos;
	int			low_index;

	get_pos(stack_a);
	tmp = *stack_a;
	low_index = INT_MAX;
	low_pos = tmp->p;
	while (tmp)
	{
		if (tmp->i < low_index)
		{
			low_index = tmp->i;
			low_pos = tmp->p;
		}
		tmp = tmp->next;
	}
	return (low_pos);
}
