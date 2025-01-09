/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:18:00 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/06 10:02:20 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stacks **stack)
{
	t_stacks	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	free_error(t_stacks **stack_a, t_stacks **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		ft_free(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		ft_free(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

int	if_isdigit(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!(av[i] >= 48 && av[i] <= 57) && av[i + 1] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	issorted(t_stacks *stack_a)
{
	t_stacks	*tmp;

	while (stack_a)
	{
		tmp = stack_a->next;
		while (tmp)
		{
			if (stack_a->v > tmp->v)
				return (0);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}

int	check_stack_dublicated(t_stacks **stack)
{
	t_stacks	*tmp_1;
	t_stacks	*tmp_2;

	tmp_1 = *stack;
	while (tmp_1)
	{
		tmp_2 = tmp_1->next;
		while (tmp_2)
		{
			if (tmp_1->v == tmp_2->v)
				return (0);
			tmp_2 = tmp_2->next;
		}
		tmp_1 = tmp_1->next;
	}
	return (1);
}
