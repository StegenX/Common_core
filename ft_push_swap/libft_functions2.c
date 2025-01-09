/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:22:15 by aagharbi          #+#    #+#             */
/*   Updated: 2025/01/05 14:46:54 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *str, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (count);
}

void	free_split(char **lst)
{
	int	i;

	i = 0;
	if (!lst)
		return ;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
	free(lst);
}

static void	fill(char const *s, char c, char **lst)
{
	size_t	word_len;
	int		i;

	i = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			word_len = f_strlen(s);
			if (f_strchr(s, c))
				word_len = f_strchr(s, c) - s;
			lst[i] = f_substr(s, 0, word_len);
			if (!lst[i])
			{
				free_split(lst);
				return ;
			}
			i++;
			s += word_len;
		}
		else
			s++;
	}
	lst[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**lst;

	if (!s)
		return (NULL);
	lst = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!lst)
		return (NULL);
	fill(s, c, lst);
	return (lst);
}

char	*f_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}
