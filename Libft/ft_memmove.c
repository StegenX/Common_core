/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:08:08 by aagharbi          #+#    #+#             */
/*   Updated: 2024/10/27 16:20:06 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*dst;
	const char	*srcc;

	dst = dest;
	srcc = src;
	if( dst == srcc)
		return (dest);
	if(dst > srcc && srcc + len >= dst)
	{
		dst += len;
		srcc += len;
		while (len--)
			*(--dst) = *(--srcc);
	}
	else
		memcpy(dst, srcc, len);
	return (dest);
}

int main ()
{
	char str[] = "aymane is here";
	char *ptr = ft_memmove(str + 11 ,str, 6);
	printf("%s", ptr);
}
