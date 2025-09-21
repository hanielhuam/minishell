/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_token_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:06:14 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/20 23:27:50 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int (*get_validation_functions(void)

static int	validate_token(t_token *token)
{
	
}

int	validate_token_list(t_dlist *tokens)
{
	while (tokens)
	{
		if (validate_token(tokens->content))
			return (1);
		tokens = tokens->next;
	}
	return (0);
}
