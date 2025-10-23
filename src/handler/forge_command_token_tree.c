/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forge_command_token_tree.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:45:48 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/23 13:38:06 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tree	*command_builder(t_tree *tree, t_dlist *token)
{
	t_tree		*node;
	t_command	*command;

	node = create_tree_by_token(token);
	if (!node)
		return (NULL);
	node->prev = tree;
	command = create_command_by_token(token);
	if (!command)
	{
		ft_treeclear(&node, del_t_tree);
		return (NULL);
	}
	((t_data_tree *)node->content)->command = command;
	return (node);
}

static t_dlist	*find_type(t_tree *init, t_tree *end, int dir, t_tok_type *type)
{
	t_dlist	*first;
	t_dlist	*last;

	first = ((t_data_tree *)init->content)->token;
	if (!end)
		last = NULL;
	else
		last = ((t_data_tree *)end->content)->token;
	first = increment_direction(first, dir);
	while (first && first != last)
	{
		if (check_token_type(first, type))
		{
			if (!end)
				return (first);
			else if (first == search_command(init, end->prev, dir))
				return (first);
			return (NULL);
		}
		first = increment_direction(first, dir);
	}
	return (NULL);
}

t_dlist	*search_command(t_tree *init, t_tree *end, int l_or_r)
{
	t_dlist				*result;
	static t_tok_type	command_types[2] = {TK_COMMAND, TK_NO_TYPE};
	static t_tok_type	redirect_types[5] = {
		TK_REDIRECT_IN, TK_HEREDOC,	TK_REDIRECT_OUT, TK_REDIRECT_OUT_OUT,
		TK_NO_TYPE
	};

	if (check_token_type(((t_data_tree *)init->content)->token, command_types) \
			|| check_token_type(((t_data_tree *)init->content)->token, \
				redirect_types))
		return (NULL);
	result = find_type(init, end, l_or_r, command_types);
	if (result)
		return (result);
	result = find_type(init, end, l_or_r, redirect_types);
	if (result)
		return (result);
	return (NULL);
}

int	forge_command_tree(t_tree *tree)
{
	return (search(tree, search_command, command_builder));
}
