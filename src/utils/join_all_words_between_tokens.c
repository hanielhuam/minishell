/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_all_words_between_tokens.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 20:50:09 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/28 23:28:01 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_words_together(char **str, t_dlist *token)
{
	char	*temp;

	temp = ft_strjoin(*str, ((t_token *)token->content)->str);
	if (!temp)
	{
		show_error("error when alloc all words\n");
		return (NULL);
	}
	free(*str);
	*str = temp;
	free(temp);
	return (*str);
}

static char	*initialization(t_dlist *begin, t_dlist *end)
{
	char	*str;

	if (!begin || !end)
		return (NULL);
	str = ft_strjoin("", ((t_token *)begin->content)->str);
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
