/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_runner.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:55:54 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/26 23:25:30 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	create_t_process(pid_t pid, t_shell shell)
{
	t_process	*process;
	t_list		*new;

	process = safe_malloc(1, sizeof(t_process), "Error when alloc t_process\n");
	if (!process)
	{
		shell->exit_code = -1;
		return (-1)
	}
	process->pid = pid;
	new = ft_lstnew(process);
	if (!new)
	{
		show_error("Error when alloc new node on process list\n");
		free(process);
		shel->exit_code = -1;
		return (-1);
	}
	ft_lstaddback(&shell->process, new);
	return (0);
}

int	child_process_runner(t_tree *node, t_shell *shell)
{
	pid_t	pid;

	pid = fork();
	if (pid > 0 && create_t_process(pid, shell))
		return (shell->exit_code);
	if (pid < 0)
	{
		show_error("Error when fork a process\n");
		shell->exit_code = -1;
		return (shell->exit_code);
	}
	if (pid == 0)
	{
		execute_command(node, shell);
		destroy_shell(shell);
	}
}
