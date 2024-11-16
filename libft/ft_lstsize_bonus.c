/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:26:06 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/08 20:58:55 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*int main()
{
    int a = 6;
    int b = 8;
    t_list *node = ft_lstnew(&a);
    t_list *node2 = ft_lstnew(&b);
    node -> next = node2;
    printf("%d", ft_lstsize(node));
    return 0;
}*/
