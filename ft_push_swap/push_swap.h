/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:16:52 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/06 13:20:53 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack
{
	int				v;
	int				i;
	int				p;
	int				tar_p;
	int				cost_a;
	int				cost_b;
	struct stack	*next;
}					t_stacks;

int					check_input(char **av);
int					arg_is_num(char *av);
void				check_op(t_stacks **stack_a, t_stacks **stack_b,
						char *line);
void				check_move(t_stacks **stack_a, t_stacks **stack_b,
						char *line);
int					is_valid(char *line);
void				duplicated_input(int ac, char **av);
int					check_stack_dublicated(t_stacks **stack);
int					arg_is_zero(char *av);
int					check_dublicated(char **av);
int					check_string(char *av);
int					if_isdigit(char *av);
void				split_nums(t_stacks **stack_a, char *av, int i);
void				free_error(t_stacks **stack_a, t_stacks **stack_b);
void				ft_free(t_stacks **stack);
t_stacks			*append_to_stack(int ac, char **av);
void				free_split(char **lst);
t_stacks			*new_stack(int value);
void				lstadd_back(t_stacks **stack_a, t_stacks *new);
int					ft_lstsize(t_stacks *lst);
void				give_index(t_stacks *stack_a, int s_size);
int					ft_strncmp(const char *s1, const char *s2);
long int			ft_atoi(const char *nptr);
t_stacks			*ft_lstlast(t_stacks *stack_a);
size_t				f_strlen(const char *s);
char				**ft_split(char const *s, char c);
char				*f_substr(const char *s, unsigned int start, size_t len);
char				*f_strdup(const char *s);
char				*f_strchr(const char *s, int c);
int					issorted(t_stacks *stack_a);
void				ft_push_swap(t_stacks **stack_a, t_stacks **stack_b);
void				swap(t_stacks **stack);
void				push(t_stacks **stack_d, t_stacks **stack_s);
void				rotate(t_stacks **stack);
void				rotate_reverse(t_stacks **stack);
void				sa(t_stacks **stack_a);
void				sb(t_stacks **stack_a);
void				ss(t_stacks **stack_a, t_stacks **stack_b);
void				pa(t_stacks **stack_a, t_stacks **stack_b);
void				pb(t_stacks **stack_a, t_stacks **stack_b);
void				ra(t_stacks **stack_a);
void				rb(t_stacks **stack_b);
void				rr(t_stacks **stack_a, t_stacks **stack_b);
void				rra(t_stacks **stack_a);
void				rrb(t_stacks **stack_b);
void				rrr(t_stacks **stack_a, t_stacks **stack_b);
void				stack_sort(t_stacks **stack_a, t_stacks **stack_b);
void				push_to_b(t_stacks **stack_a, t_stacks **stack_b);
void				get_pos(t_stacks **stack);
int					get_target(t_stacks **stack, int b_index, int targ_i,
						int target_p);
void				target_position(t_stacks **stack_a, t_stacks **stack_b);
void				count_cost(t_stacks **stack_a, t_stacks **stack_b);
int					abs_nb(int cost);
void				best_move(t_stacks **stack_a, t_stacks **stack_b);
void				move_element(t_stacks **stack_a, t_stacks **stack_b,
						int cost_a, int cost_b);
void				rotate_ab(t_stacks **stack_a, t_stacks **stack_b,
						int *cost_a, int *cost_b);
void				reverse_rotate_ab(t_stacks **stack_a, t_stacks **stack_b,
						int *cost_a, int *cost_b);
void				rotate_a(t_stacks **stack_a, int *cost);
void				rotate_b(t_stacks **stack_a, int *cost);
void				target_position(t_stacks **stack_a, t_stacks **stack_b);
void				t_sort(t_stacks **stack_a);
int					get_low_index(t_stacks **stack_a);
void				stack_shift(t_stacks **stack_a);
t_stacks			*lst_beforelast(t_stacks *stack);
int					find_highest_index(t_stacks *stack);

#endif
