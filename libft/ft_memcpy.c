/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:20:31 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/08 17:12:12 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = (char *)dest;
	s = (const char *)src;
	i = 0;
	if (n == 0 || dest == src)
		return (dest);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*int main()
{
	char dst[10];
	char *src = "aymane";
	//printf("%s", (char *)ft_memcpy(dst, src, 6));
	//printf("%s", (char *)ft_memcpy(dst, src, 0));
	//printf("%s", (char *)ft_memcpy(dst, '\0',1)); 
}*/
