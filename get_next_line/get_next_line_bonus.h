/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagharbi <aagharbi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:18:22 by aagharbi          #+#    #+#             */
/*   Updated: 2024/11/25 20:20:13 by aagharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef  BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);

char	*ft_strchr(const char *s);

char	*ft_strdup(const char *s);

char	*ft_strjoin(char *s1, const char *s2);

#endif
