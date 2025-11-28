/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:27:45 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/17 19:43:08 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_builtins(void)
{
	static char	*builtins[7] = {
		"echo", "cd", "pwd", "export", "unset", "env", NULL
	};

	return (builtins);
}

int	is_builtin(t_command *command)
{
	int		i;
	char	**builtins;

	if (!command->path)
		return (0);
	builtins = get_builtins();
	i = 0;
	while (builtins[i])
	{
		if (!ft_strncmp(command->path, builtins[i++], ft_strlen(command->path)))
			return (1);
	}
	return (0);
}
