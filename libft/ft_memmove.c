/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:08:08 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/08 18:07:15 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dst;
	unsigned char	*srcc;

	dst = (unsigned char *)dest;
	srcc = (unsigned char *)src;
	if (dst == srcc)
		return (dest);
	if (dst > srcc && (srcc + len) >= dst)
	{
		while (len--)
			dst[len] = srcc[len];
	}
	else
		ft_memcpy(dest, src, len);
	return (dest);
}
/*int main()
{
	char a[100] = "aymane aghrabi";
	
	printf("%s", (char *)ft_memmove(a + 5,a, 6));
        //printf("%s", (char *)ft_memmove(a + 8, a, 9));	
}*/
