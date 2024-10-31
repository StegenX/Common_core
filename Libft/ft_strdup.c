#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*start;

	str = (char *) malloc(strlen(s) + 1);
	if (!str)
		return (NULL);
	start = str;
	while (*s)
	{
		*str++ = *s++;
	}
	*str = '\0';
	return (start);
}
