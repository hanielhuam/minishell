/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:43:16 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/12 23:18:52 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ganerate_env_string(t_env *env, char **string)
{
	char	*result;
	char	*temp;

	temp = ft_strjoin(env->name, "=");
	if (!temp)
	{
		show_error("Error when alloc new env string\n");
		return (NULL);
	}
	result = ft_strjoin(temp, env->value);
	free(temp);
	if (!result)
	{
		show_error("Error when alloc new env string\n");
		return (NULL);
	}
	*string = result;
	return (result);
}

void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
	matrix = NULL;
}

char	**list_env_matrix(t_list *envlist)
{
	char	**matrix;
	int		size;
	int		i;

	size = ft_lstsize(envlist);
	matrix = safe_malloc(size, sizeof(char *), "Error when alloc matrix\n");
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!ganerate_env_string((t_env *)envlist->content, &matrix[i]))
		{
			free_matrix(matrix);
			return (NULL);
		}
		envlist = envlist->next;
		i++;
	}
	return (matrix);
}

char	**get_env_path(t_list *envlist)
{
	t_env	*env;

	while (envlist)
	{
		env = (t_env *)envlist->content;
		if (ft_strncmp(env->name, "PATH", ft_strlen(env->name)))
			return (modified_split(env->value, ':'));
		envlist = envlist->next;
	}
	return (NULL);
}
