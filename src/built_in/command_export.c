/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:11:29 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/19 19:24:44 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*lower_str(char **matrix, int i)
{
	char	*result;

	j = i + 1;
	result = matrix[i];
	ehile (matrix[j])
	{
		if (ft_strcmp(result, matrix[j], ft_strlen(result)) > 0)
			result = matrix[j];
		j++;
	}
	return (result);
}

static int	show_env_ordered(t_dlist *env, int fd)
{
	char	**matrix;
	int		i;

	matrix = list_env_matrix(env);
	if (!matrix)
		return (1);
	i = 0;
	while (matrix[i])
	{
		matrix[i] = lower_str(matrix, i); 
		i++;
	}
	i = 0;
	while (matrix[i])
	{
		ft_putstr_fd(matrix[i], fd);
		if (matrix[i++])
			ft_putstr_fd("\n", fd);
	}
	free_matrix(matrix);
}

int	command_export(t_command *command, t_dlist **env, int fd)
{
	t_dlist	*found;
	t_env	*new;

	if (!command->cmd_args[1])
		return (show_env_ordered(*env));
	new = str_to_t_env(command->cmd_args[1]);
	if (!new)
		return (0);
	found = find_env(*env, new->name);
	if (!found)
		ft_lstadd_back(env, ft_lstnew(new));
	else
	{
		del_t_env((t_env *)found->content);
		found->content = new;
	}
	return (0);
}
