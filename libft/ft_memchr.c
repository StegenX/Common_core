/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:01:01 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/03 11:49:39 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		i;
	const unsigned char	*ss;

	ss = s;
	i = 0;
	while (i < n)
	{
		if (ss[i] == (unsigned char)c)
			return ((void *) ss + i);
		i++;
	}
	return (NULL);
}
