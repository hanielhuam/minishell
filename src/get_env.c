/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:57:03 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/08/23 17:43:14 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	**get_env_list(char **env)
{
	t_list	**list;

	if (!env || !*env)
	{
		ft_putstr_fd(STDERR_FILENO, "Enviroment variables ate empty");
		return (NULL);
	}
	list = malloc(sizeof(t_list *));
	if (!list)
	{
		ft_putstr_fd(STDERR_FILENO, "Error while alloc list pointer");
		return (NULL);
	}
	while (*env)
	{
		
	}
}
