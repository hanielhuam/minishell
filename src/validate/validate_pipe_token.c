/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_pipe_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:37:58 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/22 20:43:16 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	validate_after_pipe_token(t_dlist *token)
{
	static t_tok_type	types[6] = {
		TK_COMMAND,
		TK_REDIRECT_IN,
		TK_HEREDOC,
		TK_REDIRECT_OUT,
		TK_REDIRECT_OUT_OUT,
		TK_NO_TYPE
	};
	
	if (!token || only_accept_tokens(((t_token *)token->content)->type, types))
	{
		syntax_error("after '|' mustn`t be ", \
				((t_token *)token->content)->str);
		return (1);
	}
	return (0);
}
