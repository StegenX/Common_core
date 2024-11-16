/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:01:01 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/08 17:10:45 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ss;

	ss = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ss[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
/*int main ()
{
	char s[] = "aymane";
	printf("%s\n", (char *)ft_memchr(s,'a', ft_strlen(s)));
	printf("%s\n", (char *)ft_memchr(s,97, ft_strlen(s)));
	printf("%s\n", (char *)ft_memchr(s, 300, ft_strlen(s)));
	printf("%s\n", (char *)ft_memchr(s, -33, ft_strlen(s)));
	return 0;
}*/
