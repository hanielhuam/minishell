/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_accept_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 22:57:51 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/25 21:05:27 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	only_accept_tokens(t_tok_type value, t_tok_type *accept)
{
	int	i;

	i = 0;
	while (accept[i] != TK_NO_TYPE)
	{
		if (value == accept[i++])
			return (0);
	}
	return (1);
}
