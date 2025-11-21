/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 19:01:34 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/20 19:09:26 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	show_t_env(void *content)
{
	t_env	*env;

	env = (t_env *)content;
	ft_printf("%s=%s\n", env->name, env->value);
}

void	show_env(t_dlist **env_list)
{
	ft_dlstiter(*env_list, show_t_env);
}

int	command_env(t_command *command, t_dlist **env, int fd)
{
	t_dlist	*init;
	t_env	*tenv;
	char	*temp;

	(void)command;
	init = *env;
	while (init)
	{
		tenv = (t_env *)init->content;
		temp = ganerate_env_string(tenv);
		if (temp)
		{
			ft_putstr_fd(temp, fd);
			ft_putstr_fd("\n", fd);
		}
		init = init->next;
		free(temp);
	}
	return (0);
}
