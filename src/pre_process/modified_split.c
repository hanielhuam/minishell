/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:07:14 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/08 20:02:10 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	if (!s || !*s)
		return (count);
	if (*s != c)
	{
		count++;
		s += (check_size_into_quotes(s) + 1);
	}
	while (*s)
	{
		if (*s != c && *(s - 1) == c)
			count++;
		s += (check_size_into_quotes(s) + 1);
	}
	return (count);
}

static size_t	end_word(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		 i += (check_size_into_quotes(&s[i]) + 1);
	return (i);
}

static const char	*make_line(char **line, const char *s, char c)
{
	size_t	end;

	end = end_word(s, c);
	*line = ft_substr(s, 0, end);
	if (!line)
		return (NULL);
	s += end;
	return (s);
}

static void	make_matrix(char **matrix, const char *s, char c, size_t sz)
{
	size_t	i;

	i = 0;
	if (!s || !*s)
		return ;
	if (*s != c)
	{
		s = make_line(&matrix[i], s, c);
		if (!s)
			return ;
		i++;
	}
	while (i < sz && *s)
	{
		if (*s != c && *(s - 1) == c)
		{
			s = make_line(&matrix[i], s, c);
			if (!s)
				return ;
			i++;
		}
		else
			s++;
	}
}

char	**modified_split(char const *s, char c)
{
	size_t		i;
	size_t		sz;
	char		**matrix;

	if (!s)
		return (NULL);
	sz = count_words(s, c);
	matrix = (char **) ft_calloc((sz + 1), sizeof(char *));
	if (!matrix)
		return (NULL);
	make_matrix(matrix, s, c, sz);
	i = 0;
	while (matrix[i])
		i++;
	if (i < sz)
	{
		show_error("Error while modified split\n");
		while (i)
			free(matrix[i--]);
		free(matrix[0]);
		free(matrix);
		return (NULL);
	}
	return (matrix);
}
