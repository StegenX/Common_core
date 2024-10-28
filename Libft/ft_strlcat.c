/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:19:39 by aagharbi          #+#    #+#             */
/*   Updated: 2024/10/25 10:43:32 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	d_len;

	len = strlen(dst) + strlen(src);
	i = 0;
	if (size <= strlen(dst))
	{
		return (len);
	}
	d_len = strlen(dst);
	while ((i < size - (len - strlen(src)) && src[i]))
	{
		dst[d_len] = src[i];
		i++;
		d_len++;
	}
	dst[d_len] = '\0';
	return (len);
}
