/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:54:59 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/28 21:17:20 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_all_pipes(t_tree *node)
{
	if (!node)
		return ;
	close_pipe_node(node);
	close_all_pipes(node->left);
	close_all_pipes(node->right);
}

void	close_pipe_node(t_tree *node)
{
	t_pipe	*pipe;

	if (!node || node->type != TK_PIPE)
		return ;
	pipe = ((t_data_tree *)node->content)->pipe;
	close(pipe->pipe[0]);
	clode(pipe->pipe[1]);
}
