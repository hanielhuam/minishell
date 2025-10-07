/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_most_valuable_token.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 21:19:12 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/06 19:38:52 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	in_type_array(t_tok_type type, t_tok_type *array)
{
	while (*array != TK_NO_TYPE)
	{
		if (type == *array)
			return (1);
	}
	return (0);
}

int	get_tokens_type_order(t_token *token)
{
	int	i;
	static t_tok_type types[8][5] = {
		{TK_FILE_IN, TK_DELIMITER, TK_FILE_OUT, TK_FILE_OUT_OUT, TK_NO_TYPE},
		{TK_ARGUMENT, TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE},
		{
			TK_REDIRECT_IN, TK_HEREDOC, TK_REDIRECT_OUT, TK_REDIRECT_OUT_OUT,
			TK_NO_TYPE
		},
		{TK_COMMAND, TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE},
		{TK_PIPE, TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE},
		{TK_SUBSHELL, TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE},
		{TK_AND, TK_OR, TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE},
		NULL
	};

	i = 0;
	while (types[i])
	{
		if (in_type_array(token->type, types[i]))
			return (i);
		i++;
	}
	return (0);
}

t_dlist	*compare_token_value(t_dlist *max, t_dlist *comp)
{
	if (get_tokens_type_order((t_token *)max->content) > \
			get_tokens_type_order((t_token *)comp->content))
		return (max);
	return (compr);
}

t_dlist	*find_most_valuable_token(t_dlist *tokens)
{
	t_dlist	*most_valuable;
	
	most_valuable = tokens;
	tokens = tokens->next;
	while (tokens)
	{
		if (compare_token_value(most_valuable, tokens) != most_valuable)
			most_valuable = tokens;
		tokens = tokens->next;
	}
	return (most_valuable);
}
