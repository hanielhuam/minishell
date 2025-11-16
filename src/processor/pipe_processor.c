/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_processor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:54:53 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/15 23:41:07 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	confg_prev(t_tree *prev, t_data_tree *le, t_data_tree *ri, int dir)
{
	t_data_tree	*parent;
	
	if (!prev)
		return (0);
	parent = (t_data_tree *)prev->content;
	if (parent->type != TK_PIPE)
		return (0);
	if (dir)
		le->pipe->fds[0] = parent->pipe->fds[0];
	else
		ri->pipe->fds[1] = parent->pipe->fds[1];
	return (0);
}

static int	config_pipe(t_pipe *pipe, t_tree *node, int dir)
{
	t_data_tree	*left;
	t_data_tree	*right;

	left = (t_data_tree *)node->left->content;
	right = (t_data_tree *)node->right->content;
	if (left->type != TK_PIPE)
	{
		left->pipe = create_t_pipe(0, pipe->fds[1]);
		if (!left->pipe)
			return (-1);
	}
	if (right->type != TK_PIPE)
	{
		right->pipe = create_t_pipe(pipe->fds[0], 0);
		if (!right->pipe)
			return (-1);
	}
	config_prev(node->prev, left, right, dir);
	return (0);
}

static t_pipe	*generate_pipe(void)
{
	t_pipe	*pipe;
	int		fds[2];

	if (pipe(fds))
	{
		show_error("Error when open pipe\n");
		return (NULL);
	}
	pipe = create_t_pipe(fds[0], fds[1]);
	if (!pipe)
	{
		close(pipe->fds[0]);
		close(pipe->fds[1]);
		free(pipe);
		return (NULL);
	}
	return (pipe);
}

int pipe_execution(t_tree *node, t_shell *shell)
{
	int	ex1;
	int	ex2;

	ex1 = execution_command_tree(node->left, shell, 0);
	close(((t_data_tree *)node->content)->pipe->fds[1]);
	ex2 = execution_command_tree(node->right, shell, 1);
	close(((t_data_tree *)node->content)->pipe->fds[0]);
	if (ex1 || ex2)
		return (-1);
	if (wait_check(node))
		return (wait(process));
	return (0);
}

int	pipe_processor(t_tree *node, t_shell *shell, int dir)
{
	t_pipe	*pipe;

	pipe = generate_pipe();
	if (!pipe)
		return (-1);
	if (config_pipes(node, pipe, dir))
	{
		close(pipe->fds[0]);
		close(pipe->fds[1]);
		free(pipe);
		return (-1);
	}
	return (pipe_execution(node, shell));
}
