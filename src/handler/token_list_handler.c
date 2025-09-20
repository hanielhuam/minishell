/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:14:12 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/16 15:03:56 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_dlist	**subshell_token_handler(t_dlist **tokens)
{
	return (tokens);
}

int	token_list_handler(t_dlist **tokens)
{
	if (validate_token_list(*tokens))
		return (-1);
	if (!subshell_token_handler(tokens))
		return (-1);
	return (0);
}
