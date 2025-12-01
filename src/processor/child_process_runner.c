/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_runner.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:55:54 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/01 17:49:40 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_t_process(pid_t pid, t_shell *shell)
{
	t_process	*process;
	t_list		*new;

	process = safe_malloc(1, sizeof(t_process), "Error when alloc t_process\n");
	if (!process)
	{
		shell->exit_code = EXIT_FAILURE;
		return (1);
	}
	process->pid = pid;
	new = ft_lstnew(process);
	if (!new)
	{
		show_error("Error when alloc new node on process list\n");
		free(process);
		shell->exit_code = EXIT_FAILURE;
		return (1);
	}
	ft_lstadd_back(&shell->process, new);
	return (0);
}

static int	emit_exitcode(t_tree *node, int exec)
{
	t_command	*command;
	DIR			*directory;

	command = ((t_data_tree *)node->content)->command;
	if (!exec)
		return (0);
	if (command->path)
	{
		directory = opendir(command->path);
		if (direcory)
		{
			show_error("minishell: can not run a directory\n");
			closedir(directory);
			return (126);
		}
		show_error("minishell: command not found\n");
		return (127);
	}
	return (EXIT_FALURE)
}

int	child_process_runner(t_tree *node, t_shell *shell)
{
	pid_t	pid;
	int		exit_code;

	pid = fork();
	if (pid > 0 && create_t_process(pid, shell))
		return (-1);
	if (pid < 0)
	{
		show_error("Error when fork a process\n");
		return (-1);
	}
	if (pid == 0)
	{
		exit_code = execute_command(node, shell);
		exit_code = emit_exitcode(node, exit_code);
		destroy_shell(shell);
		exit(exit_code);
	}
	return (0);
}
