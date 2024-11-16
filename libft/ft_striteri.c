/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:31:44 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/09 21:49:40 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*void upper(unsigned int i, char *s)
{
	if (*s >= 'a' && *s <= 'z')
		*s -= 32;
}

int main ()
{
	char s[] = "aymane";

	ft_striteri(s, upper);
	printf("%s", s);
	return 0;
}*/
