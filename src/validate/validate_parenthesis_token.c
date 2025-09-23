/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_parenthesis_token.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:51:13 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/22 21:29:47 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	validate_after_open_parenthesis_token(t_dlist *token)
{
	static t_tok_type	types[7] = {
		TK_COMMAND,
		TK_REDIRECT_IN,
		TK_HEREDOC,
		TK_REDIRECT_OUT,
		TK_REDIRECT_OUT_OUT,
		TK_OPEN_PARENTH,
		TK_NO_TYPE
	};
	
	if (!token || only_accept_tokens(((t_token *)token->content)->type, types))
	{
		syntax_error("after '(' mustn`t be ", \
				((t_token *)token->content)->str);
		return (1);
	}
	return (0);
}

int	validate_after_close_parenthesis_token(t_dlist *token)
{
	static t_tok_type	types[5] = {
		TK_AND,
		TK_OR,
		TK_OPEN_PARENTH,
		TK_CLOSE_PARENTH,
		TK_NO_TYPE
	};
	
	if (token && only_accept_tokens(((t_token *)token->content)->type, types))
	{
		syntax_error("after ')' mustn`t be ", \
				((t_token *)token->content)->str);
		return (1);
	}
	return (0);
}
