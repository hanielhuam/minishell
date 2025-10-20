/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forge_and_or_tokem_tree.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:53:07 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/19 19:40:29 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tree	*and_or_builder(t_tree *tree, t_dlist *token)
{
	t_tree	*node;

	node = create_tree_by_token(token);
	if (!node)
		return (NULL);
	node->prev = tree;
	return (node);
}

t_dlist	*search_and_or(t_tree *init, t_tree *end, int l_or_r)
{
	t_dlist				*first;
	t_dlist				*last;
	static t_tok_type	types[3] = {TK_AND, TK_OR, TK_NO_TYPE};

	first = ((t_data_tree *)init->content)->token;
	if (!end)
		last = NULL;
	else
		last = ((t_data_tree *)end->content)->token;
	first = increment_direction(first, l_or_r);
	while (first && first != last)
	{
		if (check_token_type(first, types))
		{
			if (!end)
				return (first);
			else if (first == search_and_or(init, end->prev, l_or_r))
				return (first);
			return (NULL);
		}
		first = increment_direction(first, l_or_r);
	}
	return (NULL);
}

int	forge_and_or_tree(t_tree *tree)
{
	return (search(tree, search_and_or, and_or_builder));
}
