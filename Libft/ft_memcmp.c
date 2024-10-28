/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:42:02 by aagharbi          #+#    #+#             */
/*   Updated: 2024/10/24 14:59:00 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		i;
	const char	*s;
	const char	*ss;

	s = s1;
	ss = s2;
	i = 0;
	while (n--)
	{
		if (s[i] != ss[i])
			return (s[i] - ss[i]);
	}
	return (s[i] - ss[i]);
}
