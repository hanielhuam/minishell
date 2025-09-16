/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_t_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:59:46 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:42:17 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_t_token(void *content)
{
	t_token	*token;

	token = (t_token *)content;
	free(token->str);
	if (subshell)
		ft_dlstclear(&subshell, del_t_token);
	free(token);
}

void	del_token_list(t_dlist **token_list)
{
	ft_dlstclear(token_list, del_t_token);
	free(token_list);
}
