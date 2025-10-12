/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_or.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:53:07 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/11 21:31:22 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_dlist	*find_and_or_left(t_dlist *init, t_dlist *end, int l_or_r)
{
	if (l_or_r)
		init = init->next;
	else
		init = init->before;
	while (init && init != end)
	{
		if (((t_token *)init->content)->type == TK_AND || \
				((t_token *)init->content)->type == TK_OR)
			return (init);
		if (l_or_r)
			init = init->next;
		else
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
	if (search_left(tree, find_and_or_left))
		return (1);
	if (search_right(tree, find_and_or_right))
		return (1);
	return (0);
}
