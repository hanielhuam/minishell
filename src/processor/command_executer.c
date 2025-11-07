/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_executer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:35:47 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/07 18:01:13 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	prepare_command(t_command *command, t_pipe **pipe, t_list *env)
{
	char	*command_path;
	char	*command_arg;

	if (command->path && !manipulate_command_path(command, env))
		return (-1);
	if (command->redirects && !stablish_redirects(command->redirects, pipe))
		return (-1);
	return (0);
}

static int	prepare_pipe(t_pipe *pipe)
{
	if (pipe->fd[0] > 2)
	{
		if (dup2(pipe->fd[0], STDIN_FILENO))
		{
			show_error("Error when dup pipe with STDIN\n");
			return (1);
		}
	}
	if (pipe->fd[1] > 2)
	{
		if (dup2(pipe->fd[1], STDOUT_FILENO))
		{
			show_error("Error when dup pipe with STDOUT\n");
			return (1);
		}
	}
	return (0);
}

void	execute_command(t_tree *node, t_shell *shell)
{
	t_command	*command;
	t_pipe		*pipe;
	int			exec;

	command = ((t_data_tree *)node->content)->command;
	pipe = ((t_data_tree *)node->content)->pipe;
	exec = prepare_command(commmand, &pipe, shell->env );
	if (!exec && pipe)
		exec = prepare_pipe(pipe);
	close_all_fds();
	if (!exec)
		execve(command->path, command->cmd_arg, list_env_matrix(shell->env));
}
