/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:25:23 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/06 09:52:54 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks **stack_a)
{
	swap(&(*stack_a));
	write(1, "sa\n", 3);
}

void	sb(t_stacks **stack_b)
{
	swap(&(*stack_b));
	write(1, "sb\n", 3);
}

void	ss(t_stacks **stack_a, t_stacks **stack_b)
{
	sa(&(*stack_a));
	sb(&(*stack_b));
	write(1, "ss\n", 3);
}
