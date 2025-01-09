/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appened.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:02:57 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/06 09:50:34 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_not_valid(long *nbr, char *s)
{
	*nbr = ft_atoi(s);
	return (*nbr > INT_MAX || *nbr < INT_MIN);
}

t_stacks	*append_to_stack(int ac, char **av)
{
	t_stacks	*stack_a;
	char		**split;
	long		nbr;
	int			j;	
	int			i;

	i = 1;
	stack_a = NULL;
	while (av[i])
	{
		split = ft_split(av[i], ' ');
		if (!*split)
			exit ((free_split(split), free_error(&stack_a, NULL), 1));
		j = 0;
		while (split[j] && !is_not_valid(&nbr, split[j]))
		{
			lstadd_back(&stack_a, new_stack(nbr));
			j++;
		}
		if (split[j] != NULL)
			exit ((free_split(split), free_error(&stack_a, NULL), 1));
		free_split(split);
		i++;
	}
	return (stack_a);
}

void	ft_push_swap(t_stacks **stack_a, t_stacks **stack_b)
{
	int	size;

	if (!stack_a || !*stack_a)
		return ;
	size = ft_lstsize(*stack_a);
	if (!issorted(*stack_a))
	{
		if (size == 2)
			sa(stack_a);
		else if (size == 3)
			t_sort(stack_a);
		else
			stack_sort(stack_a, stack_b);
	}
}

void	push_to_b(t_stacks **stack_a, t_stacks **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = ft_lstsize(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->i <= stack_size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}
