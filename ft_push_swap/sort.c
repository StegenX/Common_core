/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:45:24 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/05 15:51:38 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	t_sort(t_stacks **stack)
{
	int	highest;

	if (issorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->i == highest)
		ra(stack);
	else if ((*stack)->next->i == highest)
		rra(stack);
	if ((*stack)->i > (*stack)->next->i)
		sa(stack);
}

void	stack_sort(t_stacks **stack_a, t_stacks **stack_b)
{
	push_to_b(&(*stack_a), &(*stack_b));
	t_sort(stack_a);
	while (*stack_b)
	{
		target_position(&(*stack_a), &(*stack_b));
		count_cost(&(*stack_a), &(*stack_b));
		best_move(&(*stack_a), &(*stack_b));
	}
	if (!issorted(*stack_a))
		stack_shift(stack_a);
}

void	stack_shift(t_stacks **stack_a)
{
	int	stack_size;
	int	min_pos;

	stack_size = ft_lstsize(*stack_a);
	min_pos = get_low_index(stack_a);
	if (min_pos > stack_size / 2)
	{
		while (min_pos < stack_size)
		{
			rra(stack_a);
			min_pos++;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			ra(stack_a);
			min_pos--;
		}
	}
}
