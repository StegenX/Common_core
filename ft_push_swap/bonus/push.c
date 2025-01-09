/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:33:48 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/06 09:54:04 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks **stack_a, t_stacks **stack_b)
{
	push(&(*stack_a), &(*stack_b));
	write(1, "pa\n", 3);
}

void	pb(t_stacks **stack_a, t_stacks **stack_b)
{
	push(&(*stack_b), &(*stack_a));
	write(1, "pb\n", 3);
}
