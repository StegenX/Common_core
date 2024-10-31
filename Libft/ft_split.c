/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:31:59 by aagharbi          #+#    #+#             */
/*   Updated: 2024/10/31 18:01:26 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	count_words(const char *str, char c) {
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
	return count;
}

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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
		return ((char *) s);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *) s + i);
		i++;
	}
	return (NULL);
}



char	**ft_split(char const *s, char c) {
	char	**lst;
	size_t	word_len;
	int	i;

	lst = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !lst) return (0);

	i = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			word_len = ft_strlen(s);
			if (ft_strchr(s, c))
				word_len = ft_strchr(s, c) - s;
			lst[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
		s++;
	}
	lst[i] = NULL;
	return (lst);
}

int main() {
    char str[] = "I'm/at/1337/that/belong/to/42/the/network";
    char **words = ft_split(str, '/');

    if (words) {
        for (int i = 0; words[i] != NULL; i++) {
            printf("%s\n", words[i]);
            free(words[i]);  // Free each duplicated word
        }
        free(words);  // Free the array itself
    }

    return 0;
}

