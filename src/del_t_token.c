/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_t_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:59:46 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/01 21:21:09 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_t_token(void *content)
{
	t_token	*token;

	token = (t_token *)content;
	free(token->str);
	free(token);
}

void	del_token_list(t_lst **token_list)
{
	ft_lstclear(token_list, del_t_token);
	free(token_list);
}
