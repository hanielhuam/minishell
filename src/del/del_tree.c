/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:11:36 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/12 19:17:41 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_t_tree(void *content)
{
	t_data_tree	*data;

	data = content;
	if (data->type == TK_SUBSHELL)
		dell_tree(data->subtree);
	if (data->command)
		del_t_command(data->command);
	if (data->pipe)
		free(pipe);
	free(data);
}

void	dell_tree(t_tree **tree)
{
	ft_treeclear(tree, del_t_tree);
	free(tree);
}
