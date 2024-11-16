/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:28:01 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/08 21:37:51 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
/*int main()
{
    int a = 6;
    int b = 8;
    int c = 10;
    t_list **lst = malloc (sizeof(t_list));
    t_list *node = ft_lstnew(&a);
    t_list *node2 = ft_lstnew(&b);
    node -> next = node2;
    t_list *node3 = ft_lstnew(&c);
    *lst = node;
    ft_lstadd_back(lst, node3);
    printf("%d", ft_lstsize(node));
    return 0;
}*/
