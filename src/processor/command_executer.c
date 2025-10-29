/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_executer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:35:47 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/29 18:23:34 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	prepare_command(t_command *command)
{
	
}

static int	prepare_pipe(t_pipe *pipe)
{
	
}

void	execute_command(t_tree *node, t_shell *shell)
{
	t_command	*command;
	t_pipe		*pipe;
	int			exec;

	command = ((t_data_tree *)node->content)->command;
	pipe = ((t_data_tree *)node->content)->pipe;
	exec = prepare_command(commmand, shell->envlist );
	if (pipe)
		exec = prepare_pipe(pipe);
	if (exec)
		execve(command->path, command->cmd_arg, list_env_matrix(shell->env));
}
