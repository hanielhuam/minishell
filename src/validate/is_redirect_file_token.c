/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirect_file_token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:44:48 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/18 17:20:07 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*is_redirect_token(char *str, t_token *token_before)
{
	t_token	*token;

	token = NULL;
	if (!token_before)
		return (NULL);
	if (token_before->type == TK_HERE_DOC)
		token->type = TK_DELIMITER;
	else if (token_before->type == TK_REDIRECT_IN)
		token->type = TK_
	return (token);
}
