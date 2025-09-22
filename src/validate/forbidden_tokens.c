/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forbidden_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:54:00 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/21 18:50:43 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	forbidden_tokens(t_tok_type value, t_tok_type *forbidden_tokens)
{
	int	i;

	i = 0;
	while (forbidden_tokens[i] != TK_NO_TYPE)
	{
		if (value == forbidden_tokens[i++])
			return (1);
	}
	return (0);
}
