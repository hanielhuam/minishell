/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell_processor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:53:05 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/16 20:21:19 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	execute_subshell(t_tree *tree, t_shell *shell)
{
	pid_t	pid;
	int		result;

	pid = fork();
	if (pid > 0 && create_t_process(pid, shell))
		return (1);
	if (pid < 0)
	{
		show_error("Error when fork a process\n");
		return (1);
	}
	if (pid == 0)
	{
		result = execution_command_tree(tree, shell, 0);
		destroy_shell(shell);
		exit(result);
	}
	return (wait_process(shell));
}

int	subshell_processor(t_tree *node, t_shell *shell)
{
	t_data_tree	*data;

	data = (t_data_tree *)node->content;
	return (execute_subshell(*data->subtree, shell));
}
