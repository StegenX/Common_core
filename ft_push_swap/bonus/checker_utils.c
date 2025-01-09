/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:39:21 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/07 17:39:44 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	duplicated_input(int ac, char **av)
{
	t_stacks	*stack;

	stack = append_to_stack(ac, av);
	if ((!check_stack_dublicated(&stack)))
		free_error(&stack, NULL);
}
