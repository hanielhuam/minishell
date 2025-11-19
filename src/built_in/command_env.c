/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 19:01:34 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/08/25 20:30:13 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	show_env(void *content)
{
	t_env	*env;

	env = (t_env *)content;
	ft_printf("%s=%s\n", env->name, env->value);
}

void	command_env(t_dlist	**env_list)
{
	ft_dlstiter(*env_list, show_env);
}
