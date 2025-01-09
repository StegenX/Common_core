/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_instraction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:16:17 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/06 09:45:10 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stacks **stack)
{
	t_stacks	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	rotate_ab(t_stacks **stack_a, t_stacks **stack_b,
		int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(&(*stack_a), &(*stack_b));
	}
}

void	push(t_stacks **stack_d, t_stacks **stack_s)
{
	t_stacks	*tmp;

	tmp = *stack_s;
	*stack_s = tmp->next;
	tmp->next = *stack_d;
	*stack_d = tmp;
}

void	rotate(t_stacks **stack)
{
	t_stacks	*front;
	t_stacks	*last;

	front = *stack;
	last = ft_lstlast(*stack);
	last->next = front;
	*stack = (*stack)->next;
	front->next = NULL;
}

void	rotate_reverse(t_stacks **stack)
{
	t_stacks	*tmp;
	t_stacks	*last;
	t_stacks	*before_last;

	last = ft_lstlast(*stack);
	before_last = lst_beforelast(*stack);
	tmp = *stack;
	last->next = tmp;
	before_last->next = NULL;
	*stack = last;
}
