/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_t_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:22:36 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/19 21:20:28 by hmacedo-         ###   ########.fr       */
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

t_tree	*create_tree_by_token_builder(t_dlist *token)
{
	t_tree			*tree;
	int				value;
	static t_tree	*(*builders[7])(t_tree *, t_dlist *) = {
		NULL,
		NULL,
		command_builder,
		command_builder,
		pipe_builder,
		subshell_builder,
		and_or_builder
	};

	value = type_value(((t_token *)token->content)->type);
	tree = builders[value](NULL, token);
	if (!tree)
		return (NULL);
	return (tree);
}
