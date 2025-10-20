/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:06:56 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/19 19:38:40 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	search_left(t_tree *tree, t_dlist *token, void *find, void *build)
{
	t_tree	*(*handler)(t_tree *, t_dlist *);

	handler = build;
	tree->left = handler(tree, token);
	if (!tree->left || search(tree->left, find, build))
		return (1);
	return (0);
}

static int	search_right(t_tree *tree, t_dlist *token, void *find, void *build)
{
	t_tree	*(*handler)(t_tree *, t_dlist *);

	handler = build;
	tree->right = handler(tree, token);
	if (!tree->right || search(tree->right, find, build))
		return (1);
	return (0);
}

static int	search_node_leed(t_tree *tree, void *find, void *build, int l_or_r)
{
	t_dlist	*token;
	t_dlist	*(*check)(t_tree *, t_tree *, int);

	check = find;
	token = check(tree, tree->prev, l_or_r);
	if (token)
	{
		if (l_or_r && search_right(tree, token, find, build))
			return (1);
		else if (!l_or_r && search_left(tree, token, find, build))
			return (1);
	}
	return (0);
}

int	search(t_tree *tree, void *find, void *build)
{
	if (tree->left)
	{
		if (search(tree->left, find, build))
			return (1);
	}
	else
	{
		if (search_node_leed(tree, find, build, 0))
			return (1);
	}
	if (tree->right)
	{
		if (search(tree->right, find, build))
			return (1);
	}
	else
	{
		if (search_node_leed(tree, find, build, 1))
			return (1);
	}
	return (0);
}
