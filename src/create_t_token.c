/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_t_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 18:49:26 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/10 20:51:53 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.c"

t_token	*creat_t_token(char *str, t_tok_type typr)
{
	t_token	*token;

	token = safe_malloc(1, sizeof(t_token), "Error when alloc t_token\n");
	if (!token)
		return (NULL);
	token->str = str;
	token->type = type;
	return (token);
}
