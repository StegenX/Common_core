/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:31:59 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/02 14:38:27 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void	free_split(char **lst)
{
	int i;

	i = 0;
	if (!lst)
		return;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
	free(lst);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	int	i;

	if (!s)
		return NULL;
	i = 0;
	lst = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!lst)
		return NULL;
	while (*s)
	{
		if (*s != c)
		{
			word_len = 0;
			while (s[word_len] && s[word_len] != c)
				word_len++;
			lst[i] = ft_substr(s, 0, word_len);
			if (!lst[i])
			{
				free_split(lst);
				return NULL;
			}
			i++;
			s += word_len;
		}
		else
			s++;
	}
	lst[i] = NULL;
	return (lst);
}
