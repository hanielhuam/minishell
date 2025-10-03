/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_all_words_between_tokens.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 20:50:09 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/03 20:31:47 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_and_free(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	if (!temp)
	{
		show_error("error when alloc all words\n");
		return (NULL);
	}
	free(s1);
	s1 = temp;
	return (s1);
}

static char	*get_words_together(char **str, t_dlist *token)
{
	*str = join_and_free(*str, ((t_token *)token->content)->str);
	if (!*str)
		return (NULL);
	*str = join_and_free(*str, " ");
	if (!*str)
		return (NULL);
	return (*str);
}

static char	*initialization(t_dlist *begin, t_dlist *end)
{
	char	*str;

	if (!begin || !end)
		return (NULL);
	str = ft_strjoin(((t_token *)begin->content)->str, " ");
	if (!str)
	{
		show_error("Error when alloc all words\n");
		return (NULL);
	}
	return (str);
}

char	*join_all_words_between_tokens(t_dlist *begin, t_dlist *end)
{
	char	*str;

	str = initialization(begin, end);
	if (!str)
		return (NULL);
	if (begin == end)
		return (str);
	begin = begin->next;
	while (begin && begin != end)
	{
		if (!get_words_together(&str, begin))
		{
			free(str);
			return (NULL);
		}
		begin = begin->next;
	}
	if (!begin || !get_words_together(&str, begin))
	{
		free(str);
		return (NULL);
	}
	return (str);
}
