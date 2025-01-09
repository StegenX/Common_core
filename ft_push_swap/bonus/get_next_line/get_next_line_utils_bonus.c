/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:59:25 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/25 20:00:51 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s)
{
	char	*line;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (--i >= 0)
		line[i] = s[i];
	return (line);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;
	size_t	i;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc(s1_len + s2_len + 1);
	if (!result)
		return (NULL);
	while (s1 && *s1)
		result[i++] = *s1++;
	while (s2 && *s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}
