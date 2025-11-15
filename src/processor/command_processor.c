/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_processor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:07:05 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/15 16:52:14 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	command_processor(t_tree *node, t_shell *shell)
{
	if (check_main_runner(node))
		return (main_process_runner(node, shell));
	else
	{
		if (child_process_runner(node, shell))
			return (1);
	}
	if (wait_check(node))
		return (wait_process(shell));
	return (0);
}
