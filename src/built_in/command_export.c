/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:11:29 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/22 21:16:09 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	find_changelower_str(char **matrix, int i)
{
	int		j;
	char	*temp;

	j = i + 1;
	while (matrix[j])
	{
		if (ft_strncmp(matrix[i], matrix[j], ft_strlen(matrix[i])) > 0)
		{
			temp = matrix[j];
			matrix[j] = matrix[i];
			matrix[i] = temp;
		}
		j++;
	}
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
		find_changelower_str(matrix, i++); 
	i = 0;
	while (matrix[i])
	{
		ft_putstr_fd(matrix[i++], fd);
		if (matrix[i])
			ft_putstr_fd("\n", fd);
	}
	free_matrix(matrix);
	return (0);
}

void	update_env(char *str_env, t_dlist **env)
{
	t_dlist	*found;
	t_env	*new;

	new = str_to_t_env(str_env);
	if (!new)
		return ;
	found = find_env(*env, new->name);
	if (!found)
		ft_dlstadd_back(env, ft_dlstnew(new));
	else
	{
		del_t_env((t_env *)found->content);
		found->content = new;
	}
}

validate_variable(char *str)
{
	
}

int	command_export(t_command *command, t_dlist **env, int fd)
{
	if (!command->cmd_args[1])
		return (show_env_ordered(*env, fd));
	if (validate_variable)
		update_env(command->cmd_args[1], env);
	else
		show_error("minishell: export: not valid identifier\n");
	return (0);
}
