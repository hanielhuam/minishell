/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirect_file_token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:44:48 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/19 23:35:51 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	is_redirect_file_token(t_token *token_before)
{
	t_token	token;

	token.type = TK_NO_TYPE;
	if (!token_before)
		return (token);
	else if (token_before->type == TK_HEREDOC)
		token.type = TK_DELIMITER;
	else if (token_before->type == TK_REDIRECT_IN)
		token.type = TK_FILE_IN;
	else if (token_before->type == TK_REDIRECT_OUT_OUT)
		token.type = TK_FILE_OUT_OUT;
	else if (token_before->type == TK_REDIRECT_OUT)
		token.type = TK_FILE_OUT;
	return (token);
}
