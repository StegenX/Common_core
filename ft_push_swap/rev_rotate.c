/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:25:38 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/06 09:55:01 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_ab(t_stacks **stack_a, t_stacks **stack_b,
			int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(stack_a, stack_b);
	}
}

void	rra(t_stacks **stack_a)
{
	rotate_reverse(&(*stack_a));
	write(1, "rra\n", 4);
}

void	rrb(t_stacks **stack_b)
{
	rotate_reverse(&(*stack_b));
	write(1, "rrb\n", 4);
}

void	rrr(t_stacks **stack_a, t_stacks **stack_b)
{
	rotate_reverse(&(*stack_a));
	rotate_reverse(&(*stack_b));
	write(1, "rrr\n", 4);
}
