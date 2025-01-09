/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:45:56 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/06 14:50:56 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line/get_next_line.h"

int	is_valid(char *line)
{
	if ((line[0] == 's' && line[1] == 'a' && line[2] == '\n') || (line[0] == 's'
			&& line[1] == 'b' && line[2] == '\n') || (line[0] == 'p'
			&& line[1] == 'a' && line[2] == '\n') || (line[0] == 'p'
			&& line[1] == 'b' && line[2] == '\n') || (line[0] == 's'
			&& line[1] == 's' && line[2] == '\n') || (line[0] == 'r'
			&& line[1] == 'a' && line[2] == '\n') || (line[0] == 'r'
			&& line[1] == 'b' && line[2] == '\n') || (line[0] == 'r'
			&& line[1] == 'r' && line[2] == '\n') || (line[0] == 'r'
			&& line[1] == 'r' && line[2] == 'a' && line[3] == '\n')
		|| (line[0] == 'r' && line[1] == 'r' && line[2] == 'b'
			&& line[3] == '\n') || (line[0] == 'r' && line[1] == 'r'
			&& line[2] == 'r' && line[3] == '\n'))
		return (1);
	return (0);
}

void	check_move_2(t_stacks **stack_a, t_stacks **stack_b, char *line)
{
	if (line[1] == 'a')
		rotate(stack_a);
	else if (line[1] == 'b' && *stack_b)
		rotate(stack_b);
	else if (line[1] == 'r')
	{
		if (line[2] == 'a')
			rotate_reverse(stack_a);
		else if (line[2] == 'b' && *stack_b)
			rotate_reverse(stack_b);
		else if (line[2] == 'r')
		{
			if (*stack_a)
				rotate_reverse(stack_a);
			if (*stack_b)
				rotate_reverse(stack_b);
		}
	}
}

void	check_move(t_stacks **stack_a, t_stacks **stack_b, char *line)
{
	if (line[0] == 'p')
	{
		if (line[1] == 'a' && *stack_b)
			push(stack_a, stack_b);
		else if (line[1] == 'b')
			push(stack_b, stack_a);
	}
	else if (line[0] == 's')
	{
		if (line[1] == 'a')
			swap(stack_a);
		else if (line[1] == 'b' && *stack_b)
			swap(stack_b);
		else if (line[1] == 's' && *stack_b)
		{
			swap(stack_a);
			swap(stack_b);
		}
	}
	else if (line[0] == 'r')
		check_move_2(stack_a, stack_b, line);
}

void	check_op(t_stacks **stack_a, t_stacks **stack_b, char *line)
{
	char	*current_line;

	current_line = line;
	while (current_line)
	{
		if (!(is_valid(current_line)))
			free_error(stack_a, stack_b);
		check_move(stack_a, stack_b, current_line);
		free(current_line);
		current_line = get_next_line(0);
	}
	if (*stack_b)
		write(1, "KO\n", 3);
	else if (!issorted(*stack_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int ac, char **av)
{
	t_stacks	*stack_a;
	t_stacks	*stack_b;
	char		*line;

	if (ac < 2)
		return (1);
	if (!check_input(av))
		free_error(NULL, NULL);
	duplicated_input(ac, av);
	stack_b = NULL;
	stack_a = append_to_stack(ac, av);
	line = get_next_line(0);
	if (!line)
	{
		if (!issorted(stack_a))
			write(1, "KO\n", 3);
		else
			write(1, "OK\n", 3);
	}
	else
		check_op(&stack_a, &stack_b, line);
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (0);
}
