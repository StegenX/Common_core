/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:42:02 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/08 17:11:26 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	unsigned int	i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	if (!n)
		return (0);
	while (n--)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
/*int main ()
{
	//char a[] = "aymane";
	//char b[] = "aymane";
	//printf("%d", ft_memcmp(a, b, 5));
	//printf("%d", ft_memcmp('\0', "aymane", 5));
	//printf("%d", ft_memcmp('\0', '\0', 1));
	//printf("%d", ft_memcmp("aym", "aymane", 9));
}*/
