/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_t_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:21:02 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/22 21:01:58 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_t_command(t_command *command)
{
	char	**args;

	if (command->cmd_args)
	{
		args = command->cmd_args;
		while (*args)
			free(*args++);
		free(command->cmd_args);
	}
	if (command->path)
		free(command->path);
	if (command->redirects)
		ft_dlstclear(&command->redirects, del_t_redirect);
	free(command);
}
