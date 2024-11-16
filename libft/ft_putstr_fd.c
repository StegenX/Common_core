/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:41:03 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/08 20:03:00 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
/*#include <fcntl.h>
int main ()
{
	int fd = open("/home/aagharbi/Desktop/text.txt", O_RDWR | O_CREAT, 0644);
	ft_putstr_fd("aymane",fd); 
}*/
