/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:08:32 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/02 20:38:59 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putnbr(int n)
{
	char	nbr[12];
	size_t	i;
	size_t	j;
	int	num;
	char	*result;
	    
	num = (n < 0) ? -n : n;
	i = 0;
	if (n == -2147483648)
                return ft_strdup("-2147483648");
	if (n == 0)
		return ft_strdup("0");
	while (num > 0)
	{
		nbr[i++] = (num % 10) + '0';
		num /= 10;
	}
        result = malloc(i + (n < 0 ? 2 : 1));
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
	return ft_putnbr(nbr);
}
