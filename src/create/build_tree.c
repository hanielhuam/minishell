/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:37:26 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/06 21:26:39 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_tree	*tree_head(t_dlist *tokens)
{
	t_tree	*head;

	tokens = find_most_valuable_token(tokens);
}

t_tree	**build_tree(t_dlist *tokens)
{
	t_tree	**tree;

	tree = safe_malloc(1, sizeof(t_tree *), "Error when malloc tree\n");
	if (!tree)
		return (NULL);
	*tree = tree_head(tokens);

	show_tree(*tree, 0);
	return (tree);
}
