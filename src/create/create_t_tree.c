/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_t_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:22:36 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/17 17:29:00 by hmacedo-         ###   ########.fr       */
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

t_tree	*(*get_token_builder(t_dlist *token))(t_dlist *, t_tree *)
{
	int	value;
	static t_tree	*(*builders)(t_dlist *, t_tree *)[7] = {
		NULL,
		NULL,
		command_builder,
		command_builder,
		pipe_builder,
		subshell_builder,
		nd_or_builder
	};

	value = vlue_type(((t_token *)token->content)->type);
	return (builders[value]);
}

t_tree	*create_tree_by_token_builder(t_dlist *token)
{
	
}
