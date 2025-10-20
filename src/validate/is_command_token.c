/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_command_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 22:47:30 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/08 19:10:27 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	compare_types_command(t_tok_type type)
{
	int					i;
	static t_tok_type	tok_types[8] = {
		TK_PIPE,
		TK_OPEN_PARENTH,
		TK_AND,
		TK_OR,
		TK_FILE_IN,
		TK_FILE_OUT,
		TK_FILE_OUT_OUT,
		TK_DELIMITER,
	};

	i = 0;
	while (i < 8)
	{
		if (type == tok_types[i++])
			return (1);
	}
	return (0);
}

int	is_command_delimitter(t_dlist *token)
{
	t_tok_type	type;

	type = ((t_token *)token->content)->type;
	if (type == TK_PIPE || type == TK_OPEN_PARENTH || \
			type == TK_AND || type == TK_OR)
		return (1);
	return (0);
}

int	check_unique_command(t_dlist *last_token)
{
	while (last_token && !is_command_delimitter(last_token))
	{
		if (((t_token *)last_token->content)->type == TK_COMMAND)
			return (0);
		last_token = last_token->before;
	}
	return (1);
}

t_token	is_command_token(t_dlist *token_before)
{
	t_token	token;

	token.type = TK_NO_TYPE;
	if (!token_before)
		token.type = TK_COMMAND;
	else if (compare_types_command(((t_token *)token_before->content)->type) \
			&& check_unique_command(token_before))
		token.type = TK_COMMAND;
	return (token);
}
