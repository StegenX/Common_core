/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:07:01 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/03 20:45:58 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	nbr[12];
	int		i;
	long	num;

	num = n;
	i = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	while (num > 0)
	{
		nbr[i++] = (num % 10) + '0';
		num = num / 10;
	}
	while (--i >= 0)
		write(fd, &nbr[i], 1);
}
