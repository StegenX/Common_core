/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:10:17 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/02 20:32:29 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*strings_cat;
	char	*head;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strings_cat = malloc(s1_len + s2_len);
	if (strings_cat == NULL)
		return (NULL);
	head = strings_cat;
	while (*s1 || *s2)
	{
		if (*s1)
			*strings_cat++ = *s1++;
		else if (*s2)
			*strings_cat++ = *s2++;
	}
	*strings_cat = '\0';
	return (head);
}
