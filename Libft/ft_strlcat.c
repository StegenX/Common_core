/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:19:39 by aagharbi          #+#    #+#             */
/*   Updated: 2024/10/29 14:59:55 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	d_len;

	len = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	if (size <= ft_strlen(dst))
	{
		return (len);
	}
	d_len = ft_strlen(dst);
	while ((i < size - (len- ft_strlen(src)) && src[i]))
	{
		dst[d_len] = src[i];
		i++;
		d_len++;
	}
	dst[d_len] = '\0';
	return (len);
}
