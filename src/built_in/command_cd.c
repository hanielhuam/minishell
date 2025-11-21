/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:23:33 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/20 16:06:18 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	change_pwd(t_dlist **env_list)
{
	char	dir[PATH_MAX];
	char	*env;

	if (!getcwd(dir, PATH_MAX))
	{
		perror("minishell: ");
		return (1);
	}
	env = ft_strjoin("PWD=", dir);
	if (!env)
		return (1);
	update_env(env, env_list);
	return (0);
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
