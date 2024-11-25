/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:19:25 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/24 11:18:51 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	new_line(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*get_next(char **rest, char *line, char *buffer)
{
	char	*temp;

	free(buffer);
	if (*rest && **rest != '\0')
	{
		line = ft_strchr(*rest);
		temp = *rest;
		*rest = ft_strdup(*rest + ft_strlen(line));
		free(temp);
		return (line);
	}
	free(*rest);
	*rest = NULL;
	return (NULL);
}

static char	*get_line(int fd, int checker, char *line, char *buffer)
{
	static char	*rest;
	char		*temp;

	while (checker > 0)
	{
		checker = read(fd, buffer, BUFFER_SIZE);
		if (checker < 0)
			return (free(buffer), NULL);
		buffer[checker] = '\0';
		temp = rest;
		rest = ft_strjoin(rest, buffer);
		free(temp);
		if (new_line(rest))
		{
			line = ft_strchr(rest);
			temp = rest;
			rest = ft_strdup(rest + ft_strlen(line));
			free(temp);
			free(buffer);
			return (line);
		}
	}
	return (get_next(&rest, line, buffer));
}

char	*get_next_line(int fd)
{
	char	*buffer;
	int		checker;
	char	*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	checker = 1;
	return (get_line(fd, checker, line, buffer));
}

/*#include <unistd.h>

int main()
{
    int fd = open("text.txt", O_RDONLY);
	printf("%d",fd);

    char *line;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line); // Free the line after processing
    }
    return 0;
}*/
