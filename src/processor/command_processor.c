/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_processor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:07:05 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/26 17:46:37 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	command_processor(t_tree *node, t_shell *shell, int dir)
{
	if (check_main_runner(node))
		main_process_runner(node, shell, dir);
	else
		child_process_runner(node, shell, dir);
	if (wait_check(node))
		return (wait_process(shell->process));
	return (0);
}
