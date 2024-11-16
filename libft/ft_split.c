/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:31:59 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/08 20:15:01 by aagharbi         ###   ########.fr       */
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
			word_len = ft_strlen(s);
			if (ft_strchr(s, c))
				word_len = ft_strchr(s, c) - s;
			lst[i] = ft_substr(s, 0, word_len);
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
/*#include <stdio.h>
int main ()
{
	char str[] = "hello  world";
	char **ptr = ft_split(str,' ');
	int i = 0;
	if (!ptr)
		return 1;
	while (ptr[i])
	{
		printf("%s\n", ptr[i]);
		i++;
	}
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}*/
