/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_command_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 22:47:30 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/18 23:34:52 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	compare_tok_types_to_command(t_tok_type type)
{
	int					i;
	static t_tok_type	tok_types[] = {
		TK_PIPE,
		TK_OPEN_PARENTH,
		TK_AND,
		TK_OR,
		TK_FILE_IN,
		TK_FILE_OUT,
		TK_FILE_OUT_OUT,
		TK_DELIMITER,
		NULL
	};

	i = 0;
	while (tok_types[i])
	{
		if (type == tok_types[i])
			return (1);
	}
	return (0);
}

t_token	*is_command_token(char *str, t_token *token_before)
{
	t_token	*token;

	token->type = TK_COMMAND;
	if (!token_before)
		return (token);
	else if (compare_tok_types_to_command(token_before->type))
		return (token);
	return (NULL);
}
