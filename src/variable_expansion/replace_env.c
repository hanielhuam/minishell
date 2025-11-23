/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 20:27:21 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/22 23:25:40 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



char	*replace_env(char *str, t_dlist *env)
{
	char	*variable;
	char	*result;
	char	*temp;

	result = ft_strdup(str);
	if (!result)
	{
		show_error("Error When dup str on variable expansion\n");
		return (NULL);
	}
	variable = find_variable(str);
	while (variable)
	{
		if (is_expandable(result, variable))
		{
			temp = expand(result, variable);
			free(result);
			result = temp;
		}
		variable = find_variable(variable + 1);
	}
	return (result);
}
