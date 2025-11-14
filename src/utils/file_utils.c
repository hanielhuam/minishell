/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:25:33 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/13 22:45:51 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*join_path(char	*path, char *command_name)
{
	char	*result;
	char	*temp;

	temp = ft_strjoin(path, "/");
	if (!temp)
	{
		show_error("Error when join path + /\n");
		return (NULL);
	}
	result = ft_strjoin(temp, command_name);
	free(temp);
	if (!result)
		show_error("Error when join path with command_name\n");
	return (result);
}

char	*exist_file(char *command_name, char *path)
{
	char	*result;

	if (access(command_name, F_OK) != -1)
	{
		result = ft_strdup(command_name);
		if (!result)
			show_error("Error when alloc new command_path at PATH verify\n");
		return (result);
	}
	result = join_path(path, command_name);
	if (!result)
		return (NULL);
	if (access(result, F_OK) == -1)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
