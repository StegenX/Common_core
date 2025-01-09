/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:52:02 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/06 09:46:25 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_move(t_stacks **stack_a, t_stacks **stack_b)
{
	t_stacks	*tmp_b;
	int			best;
	int			cost_a;
	int			cost_b;

	tmp_b = *stack_b;
	best = INT_MAX;
	while (tmp_b)
	{
		if (abs_nb(tmp_b->cost_a) + abs_nb(tmp_b->cost_b) < best)
		{
			best = abs_nb(tmp_b->cost_a) + abs_nb(tmp_b->cost_b);
			cost_a = tmp_b->cost_a;
			cost_b = tmp_b->cost_b;
		}
		tmp_b = tmp_b->next;
	}
	move_element(stack_a, stack_b, cost_a, cost_b);
}

void	move_element(t_stacks **stack_a, t_stacks **stack_b,
		int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		reverse_rotate_ab(&(*stack_a), &(*stack_b), &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_ab(&(*stack_a), &(*stack_b), &cost_a, &cost_b);
	rotate_a(&(*stack_a), &cost_a);
	rotate_b(&(*stack_b), &cost_b);
	pa(stack_a, stack_b);
}

void	target_position(t_stacks **stack_a, t_stacks **stack_b)
{
	t_stacks	*tmp_b;
	int			tar_p;
	int			position;
	int			i;

	tar_p = 0;
	tmp_b = *stack_b;
	position = 0;
	i = 0;
	get_pos(stack_a);
	get_pos(stack_b);
	while (tmp_b)
	{
		tar_p = get_target(&(*stack_a), tmp_b->i, INT_MAX, tar_p);
		tmp_b->tar_p = tar_p;
		tmp_b = tmp_b->next;
	}
}

void	count_cost(t_stacks **stack_a, t_stacks **stack_b)
{
	t_stacks	*tmp_a;
	t_stacks	*tmp_b;
	int			size_a;
	int			size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->p;
		if (tmp_b->p > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->p) * -1;
		tmp_b->cost_a = tmp_b->tar_p;
		if (tmp_b->tar_p > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->tar_p) * -1;
		tmp_b = tmp_b->next;
	}
}
