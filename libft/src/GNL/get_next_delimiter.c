/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_delimiter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:00:53 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/02 18:05:34 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	if (!result)
		return (NULL);
	return (result);
}

static char	*read_file(int fd, char *rest, char *delimiter)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes;

	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(rest);
			return (NULL);
		}
		buffer[bytes] = '\0';
		rest = ft_strjoin_free(rest, buffer);
		if (ft_
	}
	return (rest);
}

char	*get_next_delimiter(int fd, char *delimiter)
{
	static char	*rest[OPEN_MAX] = NULL;
	char		*result;

	if (!rest[fd])
	{
		rest[fd] = ft_calloc(1, sizeof(char));
		if (!rest[fd])
			return (NULL);
	}
	rest[fd] = read_file(fd, rest[fd], delimiter);
	if (!rest[fd])
		return (NULL);
	result = next_limit(rest[fd], delimiter);
	rest[fd] = new_rest(rest[fd], delimiter);
	return (result);
}
