/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_processor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:44:48 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/04 16:43:01 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_processor(t_command *command, t_dlist **env, int fd)
{
	int			i;
	char		**builtins;
	static int	(*functions[6])(t_command *, t_dlist **, int) = {
		command_echo, command_cd, command_pwd,
		command_export, command_unset, command_env
	};

	builtins = get_builtins();
	i = 0;
	while (builtins[i])
	{
		if (!ft_strncmp(command->path, builtins[i], ft_strlen(command->path)))
			return (functions[i](command, env, fd));
		i++;
	}
	return (-1);
}
