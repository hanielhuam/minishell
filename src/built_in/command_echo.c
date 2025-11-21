/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 20:03:05 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/20 14:44:05 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	command_echo(t_command *command, t_dlist **env, int fd)
{
	int	i;
	int	flag;

	(void)env;
	flag = 0;
	if (ft_strncmp(command->cmd_args[1], "-n", ft_strlen("-n")))
		flag = 1;
	i = flag + 1;
	while (command->cmd_args[i])
		ft_putstr_fd(command->cmd_args[i++], fd);
	if (!flag)
		ft_putstr_fd("\n", fd);
	return (0);
}
