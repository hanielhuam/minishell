/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:37:26 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/07 17:51:27 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tree	*create_tree_by_token(t_dlist *token)
{
	t_data_tree	*data;
	t_tree		*node;
	
	data = create_data_t_tree(((t_token *)token->content)->type, token);
	if (!data)
		return (NULL);
	node = ft_treenew(data);
	if (!node)
	{
		del_t_tree_with_token(data);
		show_error("Error when alloc t_tree\n");
		return (NULL);
	}
	return (node);
}

static t_tree	*tree_head(t_dlist *tokens)
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
	show_tree(*tree, 0);
	return (tree);
}
