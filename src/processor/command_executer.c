/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_executer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:35:47 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/30 22:22:52 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	prepare_command(t_command *command, t_pipe *pipe, t_list *env)
{
	char	*command_path;
	char	*command_arg;

	if (command->path)
	{
		command_path = check_command_path(command->path, env);
		if (!command_path)
			return (-1);
		command->path = command_path;
		command_arg = ft_strdup(command_path);
		if (!command_arg)
			free(command_path)
	}
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
	exec = prepare_command(commmand, pipe, shell->env );
	if (!exec && pipe)
		exec = prepare_pipe(pipe);
	if (exec)
		execve(command->path, command->cmd_arg, list_env_matrix(shell->env));
}
