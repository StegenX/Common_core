/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:08:08 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/03 11:24:05 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*dst;
	const char	*srcc;

	dst = dest;
	srcc = src;
	if (dst == srcc)
		return (dest);
	if (dst > srcc && srcc + len >= dst)
	{
		dst += len;
		srcc += len;
		while (len--)
			*(--dst) = *(--srcc);
	}
	else
		ft_memcpy(dst, srcc, len);
	return (dest);
}
