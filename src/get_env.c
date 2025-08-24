/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:57:03 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/08/23 22:09:03 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_lst	*char_to_t_list(char *str_env)
{
	t_list	*node;
	t_env	*env;

	env = safe_malloc(1, sizeof(t_env), "Error when alloc t_env");
	if (!env)
		return (NULL);
	while 
}

t_list	**get_env_list(char **env)
{
	t_list	*temp;
	t_list	**list;

	if (!env || !*env)
	{
		show_error("Enviroment variables ate empty");
		return (NULL);
	}
	list = safe_malloc(1, sizeof(t_list *), "Error when alloc list pointer");
	if (!list)
		return (NULL);
	while (*env)
	{
		temp = char_to_t_list(*env++);
		if (!temp)
		{
			ft_lstclear(list, del_t_env);
			free(list);
			return (NULL);
		}
	}
	return (list);
}
