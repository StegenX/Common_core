/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:01:01 by aagharbi          #+#    #+#             */
/*   Updated: 2024/10/24 15:28:44 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ss;
	size_t		i;

	ss = s;
	i = 0;
	while (i < n)
	{
		if (ss[i] == c)
			return ((char *) ss + i);
		i++;
	}
	return (NULL);
}
