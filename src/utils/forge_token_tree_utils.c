/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forge_token_tree_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:57:18 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/12 22:51:51 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist	*increment_direction(t_dlist *token, int l_or_r)
{
	if (l_or_r)
		return (token->next);
	return (token->before);
}

int	check_token_type(t_dlist *token, t_tok_type *types)
{
	t_tok_type	value;

	value = ((t_token *)token->content)->type;
	while (*types != TK_NO_TYPE)
	{
		if (value == *types)
			return (1);
		types++;
	}
	return (0);
}
