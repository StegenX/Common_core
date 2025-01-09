/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:14:53 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/06 09:44:11 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*stack_a;
	t_stacks	*stack_b;
	int			s_size;

	if (ac < 2)
		return (0);
	if (!check_input(av))
		free_error(NULL, NULL);
	stack_b = NULL;
	stack_a = append_to_stack(ac, av);
	if (!check_stack_dublicated(&stack_a))
		free_error(&stack_a, NULL);
	s_size = ft_lstsize(stack_a);
	give_index(stack_a, s_size + 1);
	ft_push_swap(&stack_a, &stack_b);
	ft_free(&stack_a);
}
