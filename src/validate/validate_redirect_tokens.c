/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_redirect_tokens.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 22:27:22 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/21 23:26:16 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	validate_after_redirect_in_token(t_dlist *token)
{
	static t_tok_type	types[2] = {
		TK_FILE_IN,
		TK_NO_TYPE
	};

	if (!token || only_accept_tokens(((t_token *)token->content)->type, types))
	{
		show_error("syntax error: after '<' must be a file\n");
		return (1);
	}
	return (0);
}
