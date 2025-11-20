/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:57:03 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/19 19:08:38 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*build_t_env(char *str_env, int count)
{
	t_env	*env;

	env = safe_malloc(1, sizeof(t_env), "Error when alloc t_env\n");
	if (!env)
		return (NULL);
	env->name = ft_substr(str_env, 0, count);
	if (!env->name)
	{
		show_error("Error when alloc name of env\n");
		free(env);
		return (NULL);
	}
	env->value = ft_substr(str_env, count + 1, ft_strlen(str_env) - count + 1);
	if (!env->value)
	{
		show_error("Error when alloc valoe of env\n");
		free(env->name);
		free(env);
		return (NULL);
	}
	return (env);
}

t_env	*str_to_t_env(char *str_env)
{
	int		count;
	int		lenght;
	t_env	*env;

	count = 0;
	while (str_env[count] && str_env[count] != '=')
		count++;
	lenght = ft_strlen(str_env);
	if (count == lenght)
		return (NULL);
	env = build_t_env(str_env, count);
	if (!env)
		return (NULL);
	return (env);
}

static t_dlist	*str_to_t_list(char *str_env)
{
	t_dlist	*node;
	t_env	*env;

	env = str_to_t_env(str_env);
	if (!env)
		return (NULL);
	node = ft_dlstnew(env);
	if (!node)
	{
		del_t_env(env);
		show_error("Error when alloc list node of env list\n");
		return (NULL);
	}
	return (node);
}

t_list	**get_env_list(char **env)
{
	t_dlist	*temp;
	t_dlist	**list;

	if (!env || !*env)
	{
		show_error("Enviroment variables ate empty\n");
		return (NULL);
	}
	list = safe_malloc(1, sizeof(t_list *), "Error when alloc list pointer\n");
	if (!list)
		return (NULL);
	while (*env)
	{
		temp = str_to_t_list(*env++);
		if (!temp)
		{
			ft_dlstclear(list, del_t_env);
			free(list);
			return (NULL);
		}
		ft_dlstadd_back(list, temp);
	}
	return (list);
}
