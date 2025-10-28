/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_executer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:35:47 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/28 17:17:21 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command(t_tree *node, t_shell *shell)
{
	t_command	*command;
	t_pipe		*pipe;

	command = ((t_data_tree *)node->content)->command;
	pipe = ((t_data_tree *)node->content)->pipe;
	
}
