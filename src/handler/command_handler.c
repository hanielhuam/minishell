/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:36:33 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/12 22:58:52 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_command_path(char *command_path, t_list *env)
{
	char	*result;
	char	**path;
	int		i;

	path = get_env_path(env);
	if (!path)
		return (NULL);
	i = 0;
	while (path[i])
	{
		result = exist_file(command_path, path[i++]);
		if (result)
			return (result);
	}
	return (NULL);
}

char	*manipulate_command_path(t_command *command, t_list *env)
{
	char	*command_path;
	char	*command_arg;
	
	command_path = check_command_path(command->path, env);
	if (!command_path)
		return (command->path);
	command_arg = ft_strdup(command_path);
	if (!command_arg)
	{
		free(command_path);
		show_error("Error when duplicate command_path\n");
		return (NULL);
	}
	free(command->path);
	free(command->cmd_args[0]);
	command->path = command_path;
	command->cmd_args[0] = command_arg;
	return (command_path);
}
