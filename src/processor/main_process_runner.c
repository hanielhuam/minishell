/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_process_runner.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:08:30 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/26 18:53:02 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_main_runner(t_tree *node)
{
	if (node->prev && compare_treenode_type(node->prev, 1, TK_PIPE))
		return (0);
	if (!is_builtin(((t_data_tree *)node->content)->command))
		return (0);
	return (1);
}
