/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:23:33 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/04 16:05:32 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	change_pwd(t_dlist **env_list)
{
	char	dir[PATH_MAX];
	char	*new;
	char	*old;
	t_dlist	*old_env;

	if (!getcwd(dir, PATH_MAX))
	{
		perror("minishell: ");
		return (1);
	}
	new = ft_strjoin("PWD=", dir);
	if (!new)
		return (1);
	old_env = find_env(*env_list, "PWD");
	if (old_env)
	{
		old = ft_strjoin("OLDPWD=", ((t_env *)old_env->content)->value);
		if (old)
			update_env(old, env_list);
		free(old);
	}
	update_env(new, env_list);
	free(new);
	return (0);
}

static int	change_to_home(t_dlist *env_list)
{
	t_dlist	*home_env;

	home_env = find_env(env_list, "HOME");
	if (!home_env)
	{
		show_error("variable was not found\n");
		return (1);
	}
	if (chdir(((t_env *)home_env->content)->value))
	{
		perror("minishell");
		return (1);
	}
	return (0);
}

int	command_cd(t_command *command, t_dlist **env, int fd)
{
	(void)fd;
	if (!command->cmd_args[1])
	{
		if (change_to_home(*env))
			return (1);
	}
	else if (chdir(command->cmd_args[1]))
	{
		perror("minishell");
		return (1);
	}
	if (change_pwd(env))
		return (1);
	return (0);
}
