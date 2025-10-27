/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:27:45 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/26 18:49:16 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_command *command)
{
	int			i;
	static char	*builtins[8] = {
		"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL
	};

	if (!command->path)
		return (0);
	i = 0;
	while (builtins[i])
	{
		if (!ft_strncmp(command->path, builtins[i++], ft_strlen(command->path)))
			return (1);
	}
	return (0);
}
