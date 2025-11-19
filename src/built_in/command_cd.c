/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:23:33 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/17 21:20:43 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	change_pwd(t_dlist **env)
{
	char	*dir;

	dir = getcwd(NULL, 0);
	if (!dir)
	{
		perror("minishell: ");
		return (1);
	}

}

int	command_cd(t_command *command, t_dlist **env, int fd)
{
	(void)fd;
	if (chdir(command->cmd_args[1]))
	{
		perror("minishell: ");
		return (1);
	}
	if (change_pwd(env))
		return (1);
	return (0);
}
