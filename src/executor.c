/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:32:18 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/23 23:07:32 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execution_chain(t_tree *node, t_list **env)
{
	if (compare_treenode_type(node, 2, TK_AND, TK_OR) && \
			and_or_processor(node, env))
		return (1);
	else if (compare_treenode_type(node, 1, TK_SUBSHELL) && \
			subshell_processor(node, env))
		return (1);
	else if (compare_treenode_type(node, 1, TK_PIPE) && \
			pipe_processor(node, env))
		return (1);
	else if (compare_treenode_type(node, 5, TK_COMMAND, TK_REDIRECT_IN, \
				TK_REDIRECT_OUT, TK_HEREDOC, TK_REDIRECT_OUT_OUT) && \
			command_processor(node, env))
		return (1);
	return (0);
}

void	executor(t_shell *shell)
{
	execution_chain(*shell->tree, shell->env);
}
