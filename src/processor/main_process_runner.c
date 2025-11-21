/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_process_runner.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:08:30 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/20 18:04:01 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_main_runner(t_tree *node)
{
	if (node->prev && compare_treenode_type(node->prev, 1, TK_PIPE))
		return (0);
	if (!is_builtin(((t_data_tree *)node->content)->command))
		return (0);
	return (1);
}

static int	get_fd_out(t_pipe *pipe)
{
	if (!pipe)
		return (STDOUT_FILENO);
	return (pipe->fds[1]);
}

int	main_process_runner(t_tree *node, t_shell *shell)
{
	t_command	*command;
	t_pipe		**pipe;

	command = ((t_data_tree *)node->content)->command;
	pipe = &((t_data_tree *)node->content)->pipe;
	if (command->redirects && stablish_redirects(command->redirects, pipe))
		return (-1);
	builtin_processor(command, shell->env, get_fd_out(*pipe));
	close_one_pipe(*pipe);
	close_redirects(command->redirects);
	return (0);
}
