/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_processor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:50:15 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/04 16:43:51 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	execute_side(t_tree *node, t_shell *shell, int dir)
{
	int	result;

	result = execution_command_tree(node, shell, dir);
	if (result < 0)
		return (1);
	if (shell->process)
		result = wait_process(shell);
	return (result);
}

static int	and_process(t_tree *node, t_shell *shell)
{
	int	result;

	result = execute_side(node->left, shell, 0);
	if (result)
		return (result);
	return (execute_side(node->right, shell, 1));
}

static int	or_process(t_tree *node, t_shell *shell)
{
	int	result;

	result = execute_side(node->left, shell, 0);
	if (!result || result == 130)
		return (result);
	return (execute_side(node->right, shell, 1));
}

int	and_or_processor(t_tree *node, t_shell *shell)
{
	int	result;

	if (((t_data_tree *)node->content)->type == TK_AND)
		result = and_process(node, shell);
	else
		result = or_process(node, shell);
	return (result);
}
