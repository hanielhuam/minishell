/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:37:26 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/17 15:24:02 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_tree	**tree_head(t_dlist *tokens)
{
	t_tree		**head;

	head = safe_malloc(1, sizeof(t_tree *), "Error when malloc tree\n");
	if (!head)
		return (NULL);
	tokens = find_most_valuable_token(tokens);
	*head = create_tree_by_token(tokens);
	if (!*head)
	{
		free(head);
		return (NULL);
	}
	return (head);
}

t_tree	**build_tree(t_dlist *tokens)
{
	t_tree	**tree;

	tree = tree_head(tokens);
	if (!tree)
		return (NULL);
	if (forge_and_or_tree(*tree) || forge_subshell_tree(*tree) || \
			forge_pipe_tree(*tree) || forge_command_tree(*tree))
	{
		dell_tree(tree);
		return (NULL);
	}
	return (tree);
}
