/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:44:53 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/01 15:55:39 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	wait_check(t_tree *node)
{
	if (!node->prev)
		return (1);
	if (compare_treenode_type(node, 2, TK_AND, TK_OR))
		return (1);
	if (compare_treenode_type(node, 1, TK_SUBSHELL))
		return (1);
	return (0);
}

static int	extract_statuscode(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status) + 128);
	return (status);
}

int	wait_process(t_shell *shell)
{
	int 	status;
	t_list	*init;

	if (!shell->process)
		return (0);
	init = shell->process;
	while (init)
	{
		waitpid(((t_process *)init->content)->pid, &status, 0);
		init = init->next;
	}
	ft_lstclear(&shell->process, free);
	shell->exit_code = extract_statuscode(status);
	set_exit_code(shell->exit_code);
	return (shell->exit_code);
}
