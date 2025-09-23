/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_or_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:09:51 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/22 20:26:32 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	validate_and_or_tok(t_tok_type value)
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

	return (only_accept_tokens(value, types));
}

int	validate_after_and_token(t_dlist *token)
{
	if (!token || validate_and_or_tok(((t_token *)token->content)->type))
	{
		syntax_error("after '&&' mustn`t be ", \
				((t_token *)token->content)->str);
		return (1);
	}
	return (0);
}

int	validate_after_or_token(t_dlist *token)
{
	if (!token || validate_and_or_tok(((t_token *)token->content)->type))
	{
		syntax_error("after '||' mustn`t be ", \
				((t_token *)token->content)->str);
		return (1);
	}
	return (0);
}
