/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_executer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:35:47 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/20 14:38:48 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	prepare_command(t_command *command, t_pipe **pipe, t_dlist *env)
{
	if (command->path && !manipulate_command_path(command, env))
		return (-1);
	if (command->redirects && stablish_redirects(command->redirects, pipe))
		return (-1);
	return (0);
}

static int	prepare_pipe(t_pipe *pipe)
{
	if (pipe->fds[0] > 2)
	{
		if (dup2(pipe->fds[0], STDIN_FILENO) < 0)
		{
			show_error("Error when dup pipe with STDIN\n");
			return (1);
		}
	}
	if (pipe->fds[1] > 2)
	{
		if (dup2(pipe->fds[1], STDOUT_FILENO) < 0)
		{
			show_error("Error when dup pipe with STDOUT\n");
			return (1);
		}
	}
	return (0);
}

static int	run_proc_builtin(t_command *command, t_shell *shell)
{
	int	result;

	result = builtin_processor(command, shell->env, STDOUT_FILENO);
	destroy_shell(shell);
	exit(result);
	return (-1);
}

void	execute_command(t_tree *node, t_shell *shell)
{
	t_command	*command;
	t_pipe		**pipe;
	int			exec;
	char		**env;

	command = ((t_data_tree *)node->content)->command;
	pipe = &((t_data_tree *)node->content)->pipe;
	exec = prepare_command(command, pipe, *shell->env );
	if (!exec && *pipe)
		exec = prepare_pipe(*pipe);
	close_all_fds(*shell->tree, command->redirects);
	if (!exec && command->path)
	{
		if (is_builtin(command) && run_proc_builtin(command, shell))
			return ;
		env = list_env_matrix(*shell->env);
		if (env)
		{
			execve(command->path, command->cmd_args, env);
			free_matrix(env);
		}
	}
}
