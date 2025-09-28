/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_all_words_between_tokens.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 20:50:09 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/27 21:48:43 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_words_together(char **str, t_dlist *token)
{
	char	*temp;

	temp = ft_strjoin(*str, token->str);
	if (!temp)
	{
		show_error("error when alloc alld words\n");
		return (NULL);
	}
	free(*str);
	*str = temp;
	free(temp);
	return (*str);
}

static char	*initialization(t_dlist *begin, t_dlis *end)
{
	char	*str;

	if (!begin || !end)
		return (NULL);
	str = ft_strjoin("", begin->str);
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
	tokens = tokens->next;
	while (begin && begin != end)
	{
		if (!get_words_together(&str, begin))
		{
			free(str);
			return (NULL);
		}
		begin = begin->next;
	}
	if (!bgin || !get_words_together(&str, begin))
	{
		free(str);
		return (NULL);
	}
	return (str);
}
