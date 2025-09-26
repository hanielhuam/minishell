/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_command_arg_token.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:19:08 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/25 21:06:44 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	validate_cmd_arg_tok(t_tok_type value)
{
	static t_tok_type	types[7] = {
		TK_FILE_IN,
		TK_DELIMITER,
		TK_FILE_OUT,
		TK_FILE_OUT_OUT,
		TK_COMMAND,
		TK_OPEN_PARENTH,
		TK_NO_TYPE
	};

	return (forbidden_tokens(value, types));
}

int	validate_after_command_token(t_dlist *token)
{
	if (token && validate_cmd_arg_tok(((t_token *)token->content)->type))
	{
		syntax_error("after a command mustn`t be ", \
				((t_token *)token->content)->str);
		return (1);
	}
	return (0);
}

int	validate_after_argument_token(t_dlist *token)
{
	if (token && validate_cmd_arg_tok(((t_token *)token->content)->type))
	{
		syntax_error("after a command argument mustn`t be ", \
				((t_token *)token->content)->str);
		return (1);
	}
	return (0);
}
