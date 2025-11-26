/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 20:27:21 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/25 21:25:37 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*extract_variable(char *variable)
{
	int	i;

	if (!*variable)
		return (ft_strdup(""));
	i = 0;
	while (ft_isalnum(variable[i]) || variable[i] == '_')
		i++;
	return (ft_substr(variable, 0, i));
}

static char	*replace_variable(char *variable, t_dlist *env)
{
	char	*extract;
	t_dlist	*find;
	char	*result;

	extract = extract_variable(variable + 1);
	if (!extract)
		return (NULL);
	find = find_env(env, extract);
	result = ft_substr(variable, ft_strlen(extract) + 1, ft_strlen(variable));
	free(extract);
	if (!result)
		return (NULL);
	if (find)
		extract = ft_strdup(((t_env *)find->content)->value);
	else
		extract = ft_strdup("");
	if (!extract)
	{
		free(result);
		return (NULL);
	}
	return (ft_strmerge(extract, result));
}

static char	*expand(char *str, char *variable, t_dlist *env)
{
	char	*result;
	char	*init;

	init = ft_substr(str, 0, ft_strlen(str) - ft_strlen(variable));
	if (!init)
		return (NULL);
	result = replace_variable(variable, env);
	if (!result)
	{
		free(init);
		return (NULL);
	}
	return (ft_strmerge(init, result));
}

static char *evaluate_expand_variable(char *result, t_dlist *env)
{
	char    *temp;
	char	*variable;

	variable = ft_strchr(result, '$');
	while (variable)
	{
		if (is_expandable(&result, &variable))
		{
			temp = expand(result, variable, env);
			free(result);
			if (!temp)
				return (NULL);
			result = temp;
			variable = ft_strchr(result, '$');
		}
		else
			variable = ft_strchr(variable + 1, '$');
	}
	return (result);
}

char	*replace_env(char *str, t_dlist *env)
{
	char	*result;

	result = ft_strdup(str);
	if (!result)
	{
		show_error("Error When dup str on variable expansion\n");
		return (NULL);
	}
	return (evaluate_expand_variable(result, env));
}
