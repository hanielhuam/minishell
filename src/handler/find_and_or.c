/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_or.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:53:07 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/10 21:04:03 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_dlist	*find_and_or_left(t_dlist *init, t_dlist *end)
{
	init = init->before;
	while (init && init != end)
	{
		if (((t_token *)init->content)->type == TK_AND || \
				((t_token *)init->content)->type == TK_OR)
			return (init);
		init = init->before;
	}
	return (NULL);
}

static t_dlist	*find_and_or_right(t_dlist *init, t_dlist *end)
{
	init = init->next;
	while (init && init != end)
	{
		if (((t_token *)init->content)->type == TK_AND || \
				((t_token *)init->content)->type == TK_OR)
			return (init);
		init = init->next;
	}
	return (NULL);
}

int	find_and_or(t_tree *tree)
{
	if (search_left(tree->left, find_end_or_left))
		return (1);
	if (search_right(tree->right, find_and_or_right))
		return (1);
	return (0);
}
