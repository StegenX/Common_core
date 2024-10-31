/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:08:32 by aagharbi          #+#    #+#             */
/*   Updated: 2024/10/30 17:33:18 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_putnbr(int n)
{
	char	nbr[12];
	size_t	i;
	size_t	j;
	unsigned int num;
	    
	num = (n < 0) ? -n : n;
	i = 0;
	if (n == 0)
		return strdup("0");
	while (num > 0)
	{
		nbr[i++] = (num % 10) + '0';
		num /= 10;
	}
        char *result = (char *)malloc(i + 1);
	if (!result)
		return NULL;
	j = 0;
	if (n < 0)
		result[j++] = '-';
	while (i > 0)
		result[j++] = nbr[--i];
	result[j] = '\0';
	return result;
}

char	*ft_itoa(int nbr)
{
	if (nbr == -2147483648)
		return strdup("-2147483648");
	return ft_putnbr(nbr);
}
