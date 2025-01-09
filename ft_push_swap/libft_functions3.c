/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:33:44 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/05 14:47:10 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stacks *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	lstadd_back(t_stacks **stack_a, t_stacks *new)
{
	t_stacks	*last;

	if (!new)
		return ;
	if (!*stack_a)
	{
		*stack_a = new;
		return ;
	}
	last = ft_lstlast(*stack_a);
	last->next = new;
	new->next = NULL;
}

t_stacks	*ft_lstlast(t_stacks *stack_a)
{
	if (!stack_a)
		return (NULL);
	while (stack_a && stack_a->next)
		stack_a = stack_a->next;
	return (stack_a);
}

void	ft_lstadd_front(t_stacks **lst, t_stacks *new)
{
	new->next = *lst;
	*lst = new;
}

t_stacks	*new_stack(int value)
{
	t_stacks	*new;

	new = malloc(sizeof(t_stacks));
	if (!new)
		return (NULL);
	new->v = value;
	new->next = NULL;
	return (new);
}
