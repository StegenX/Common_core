#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);

char	*ft_strchr(const char *s);

char	*ft_strdup(const char *s);

char	*ft_strjoin(char *s1, const char *s2);

#endif
