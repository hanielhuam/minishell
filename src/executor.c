/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:32:18 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/16 18:28:18 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execution_command_tree(t_tree *node, t_shell *shell, int dir)
{
	if (!node)
		return (0);
	if (compare_treenode_type(node, 2, TK_AND, TK_OR))
		return (and_or_processor(node, shell));
	else if (compare_treenode_type(node, 1, TK_SUBSHELL))
		return (subshell_processor(node, shell));
	else if (compare_treenode_type(node, 1, TK_PIPE))
		return (pipe_processor(node, shell, dir));
	else if (compare_treenode_type(node, 5, TK_COMMAND, TK_REDIRECT_IN, \
			TK_REDIRECT_OUT, TK_HEREDOC, TK_REDIRECT_OUT_OUT))
		return (command_processor(node, shell));
	return (0);
}

void	executor(t_shell *shell)
{
	shell->exit_code = execution_command_tree(*shell->tree, shell, 0);
}
