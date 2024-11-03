/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:25:23 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/03 11:25:28 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*start;

	str = (char *) malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	start = str;
	while (*s)
	{
		*str++ = *s++;
	}
	*str = '\0';
	return (start);
}
