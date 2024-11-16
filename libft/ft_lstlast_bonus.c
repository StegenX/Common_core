/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:05:41 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/08 20:55:43 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
/*int main()
{
    int a = 6;
    int b = 8;
    t_list *node = ft_lstnew(&a);
    t_list *node2 = ft_lstnew(&b);
    node -> next = node2;
    t_list *lst = ft_lstlast(node);
    printf("%d", *(int *)lst -> content);
    return 0;
}*/
