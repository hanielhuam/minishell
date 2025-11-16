/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:44:53 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/16 20:05:45 by hmacedo-         ###   ########.fr       */
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

int	wait_process(t_shell *shell)
{
	t_list	*init;

	if (!shell->process)
		return (0);
	init = shell->process;
	while (init)
	{
		waitpid(((t_process *)init->content)->pid, &shell->exit_code, 0);
		init = init->next;
	}
	ft_lstclear(&shell->process, free);
	return (shell->exit_code);
}
