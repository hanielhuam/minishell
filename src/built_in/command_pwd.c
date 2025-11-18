/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:38:48 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/17 21:11:12 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	command_pwd(t_command *command, t_list **env, int fd)
{
	char	dir[PATH_MAX];

	(void)command;
	(void)env;
	dir = getcwd(dir, PATH_MAX);
	if (!dir)
	{
		perror("minishell: ");
		return (1);
	}
	ft_putstr_fd(fd, dir);
	return (0);
}
