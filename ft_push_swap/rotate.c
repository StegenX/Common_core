/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:27:50 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/06 09:52:01 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(stack_a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(stack_a);
			(*cost)++;
		}
	}
}

void	rotate_b(t_stacks **stack_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(stack_b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(stack_b);
			(*cost)++;
		}
	}
}

void	ra(t_stacks **stack_a)
{
	rotate(&(*stack_a));
	write(1, "ra\n", 3);
}

void	rb(t_stacks **stack_b)
{
	rotate(&(*stack_b));
	write(1, "rb\n", 3);
}

void	rr(t_stacks **stack_a, t_stacks **stack_b)
{
	rotate(&(*stack_a));
	rotate(&(*stack_b));
	write(1, "rr\n", 3);
}
