/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_processor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:07:05 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/26 23:25:42 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	command_processor(t_tree *node, t_shell *shell, int dir)
{
	if (check_main_runner(node))
	{
		if (main_process_runner(node, shell))
			return (shell->exit_code);
	}
	else
	{
		if (child_process_runner(node, shell))
			return (shell->extir_code);
	}
	if (wait_check(node))
		return (wait_process(shell));
	return (shell->exit_code);
}
