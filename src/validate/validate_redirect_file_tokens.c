/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_redirect_file_tokens.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:31:14 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/25 20:55:52 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	validate_file_token(t_tok_type value)
{
	static t_tok_type	types[7] = {
		TK_ARGUMENT,
		TK_OPEN_PARENTH,
		TK_FILE_IN,
		TK_DELIMITER,
		TK_FILE_OUT,
		TK_FILE_OUT_OUT,
		TK_NO_TYPE
	};

	return (forbidden_tokens(value, types));
}

int	validate_after_file_in_token(t_dlist *token)
{
	if (token && validate_file_token(((t_token *)token->content)->type))
	{
		syntax_error("after file_in mustn`t be ", \
				((t_token *)token->content)->str);
		return (1);
	}
	return (0);
}

int	validate_after_file_out_token(t_dlist *token)
{
	if (token && validate_file_token(((t_token *)token->content)->type))
	{
		syntax_error("after file_out mustn`t be ", \
				((t_token *)token->content)->str);
		return (1);
	}
	return (0);
}

int	validate_after_delimiter_token(t_dlist *token)
{
	if (token && validate_file_token(((t_token *)token->content)->type))
	{
		syntax_error("after heredoc delimiter mustn`t be ", \
				((t_token *)token->content)->str);
		return (1);
	}
	return (0);
}

int	validate_after_file_out_out_token(t_dlist *token)
{
	if (token && validate_file_token(((t_token *)token->content)->type))
	{
		syntax_error("after append file_out mustn`t be ", \
				((t_token *)token->content)->str);
		return (1);
	}
	return (0);
}
