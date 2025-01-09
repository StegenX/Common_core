/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:15:22 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/05 14:22:05 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(const char *nptr)
{
	long int	nb;
	int			sign;

	nb = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		nb = nb * 10 + (*nptr - 48);
		nptr++;
	}
	return (nb * sign);
}

int	ft_strncmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' || s2[j] != '\0')
	{
		if (s1[i] != s2[j])
			return ((unsigned char)s1[i] - (unsigned char)s2[j]);
		i++;
		j++;
	}
	return (0);
}

size_t	f_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*f_substr(const char *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	str_len;
	size_t	i;

	if (!s)
		return (NULL);
	str_len = f_strlen(s);
	if (start >= str_len)
		return (f_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		new_str[i++] = s[start++];
	new_str[i] = '\0';
	return (new_str);
}

char	*f_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(f_strlen(s) + 1);
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
