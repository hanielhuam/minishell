/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:40:00 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/29 23:17:17 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_all_digit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (0);
	}
	return (1);
}

void	end_shell(int result, t_shell *shell)
{
	destroy_shell(shell);
	exit(result);
}

int	command_exit(t_command *command, t_shell *shell, int fd)
{
	int	result;

	ft_putstr_fd("exit\n", fd);
	result = 0;
	close_all_fds(*shell->tree, command->redirects);
	if (command->cmd_args[1] && is_all_digit(command->cmd_args[1]))
		result = ft_atoi(command->cmd_args[1]);
	if (command->cmd_args[1] && !is_all_digit(command->cmd_args[1]))
	{
		result = 2;
		show_error("minishell: exit: numeric argument required\n");
	}
	else if (command->cmd_args[1] && command->cmd_args[2])
	{
		show_error("minishell: exit: too many arguments\n");
		return (1);
	}
	end_shell(result, shell);
	return (result);
}
