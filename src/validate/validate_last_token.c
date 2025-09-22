/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_last_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:01:01 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/21 19:06:07 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	validate_last_token(t_token *token)
{
	static t_tok_type	types[9] = {
		TK_REDIRECT_IN,
		TK_HERE_DOC,
		TK_REDIRECT_OUT,
		TK_REDIRECT_OUT_OUT,
		TK_PIPE,
		TK_AND,
		TK_OR,
		TK_OPEN_PARENTH,
		TK_NO_TYPE
	};

	if (forbidden_tokens(token->type, types))
	{
		syntax_error("last token mustn`t be ", token->str);
		return (1);
	}
	return (0);
}
