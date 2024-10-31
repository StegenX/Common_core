/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:02:15 by aagharbi          #+#    #+#             */
/*   Updated: 2024/10/30 17:11:23 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*new_str;
	char	*strt;
	char	*fault;

	new_str = (char *) malloc (len + 1);
	if (start > strlen(s))
		return (NULL);
	if (new_str == NULL)
		return (NULL);
	strt = new_str;
	while (len--)
	{
		*new_str++ = s[start++];
	}
	*new_str = '\0';
	return (strt);
}
