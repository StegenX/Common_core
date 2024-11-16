/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:29:15 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/08 19:51:52 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*new_string;

	start = 0;
	if (!s1)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	new_string = malloc(end - start + 1);
	if (new_string == NULL)
		return (NULL);
	ft_memcpy(new_string, s1 + start, end - start + 1);
	new_string[end - start] = '\0';
	return (new_string);
}
/*int main ()
{
	char *a = "aabbccbbaa";
	printf("%s", ft_strtrim(a, "ab"));
}*/
