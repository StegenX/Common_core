/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:56:23 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/26 20:01:01 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	free(buffer);
	if (*rest && **rest != '\0')
	{
		line = ft_strchr(*rest);
		free(*rest);
		*rest = NULL;
		return (line);
	}
	free(*rest);
	*rest = NULL;
	return (NULL);
}

static char	*get_line(int fd, int checker, char *line, char *buffer)
{
	static char	*rest[1024];
	char		*temp;

	while (checker > 0)
	{
		checker = read(fd, buffer, BUFFER_SIZE);
		if (checker < 0)
			return (free(buffer), NULL);
		buffer[checker] = '\0';
		temp = rest[fd];
		rest[fd] = ft_strjoin(rest[fd], buffer);
		free(temp);
		if (new_line(rest[fd]))
		{
			line = ft_strchr(rest[fd]);
			temp = rest[fd];
			rest[fd] = ft_strdup(rest[fd] + ft_strlen(line));
			free(temp);
			free(buffer);
			return (line);
		}
	}
	return (get_next(&rest[fd], line, buffer));
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
