/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:38:56 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/20 17:39:23 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist	*find_env(t_dlist *env_list, char *env_name)
{
	t_env	*env;

	while (env_list)
	{
		env = (t_env *)env_list->content;
		if (!ft_strncmp(env_name, env->name, ft_strlen(env_name)))
			return (env_list);
		env_list = env_list->next;
	}
	return (NULL);
}

int	command_unset(t_command *command, t_dlist **env, int fd)
{
	t_dlist	*found;

	(void)fd;
	if (!command->cmd_args[1])
		return (0);
	found = find_env(*env, command->cmd_args[1]);
	if (!found)
		return (0);
	if (*env == found)
	{
		*env = (*env)->next;
		if (*env)
			(*env)->before = NULL;
		ft_dlstdelone(found, del_t_env);
	}
	else
	{
		found->before->next = found->next;
		found->next->before = found->before;
		ft_dlstdelone(found, del_t_env);
	}
	return (0);
}
