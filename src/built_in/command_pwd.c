/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:38:48 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/20 19:13:35 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	command_pwd(t_command *command, t_dlist **env, int fd)
{
	char	dir[PATH_MAX];

	(void)command;
	(void)env;
	if (!getcwd(dir, PATH_MAX))
	{
		perror("minishell");
		return (1);
	}
	ft_putstr_fd(dir, fd);
	ft_putstr_fd("\n", fd);
	return (0);
}
