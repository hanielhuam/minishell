/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:37:26 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/10 22:57:13 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tree	*create_tree_by_token(t_dlist *token)
{
	t_data_tree	*data;
	t_tree		*node;
	
	data = create_t_data_tree(((t_token *)token->content)->type, token);
	if (!data)
		return (NULL);
	node = ft_treenew(data);
	if (!node)
	{
		del_t_tree(data);
		show_error("Error when alloc t_tree\n");
		return (NULL);
	}
	return (node);
}

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
	if (forge_and_or_tree(*tree) || forge_subshell_tree(*tree))
	{
		dell_tree(tree);
		return (NULL);
	}
	show_tree(*tree, 0);
	return (tree);
}
