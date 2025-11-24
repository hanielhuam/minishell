/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 22:59:38 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/23 22:38:05 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	variable_expander(char **str, t_dlist *env)
{
	char	*result;
	char	*temp;

	if (!str || !*str)
		return (1);
	temp = replace_env(*str, env);
	if (!temp)
		return (1);
	result = remove_quotes(temp);
	free(temp);
	if (!result)
		return (1);
	free(*str);
	*str = result;
	return (0);
}

int	variable_expansion(t_command *command, t_dlist *env)
{
	int		i;
	t_dlist	*init;

	variable_expander(&command->path, env);
	i = 0;
	while (command->cmd_args[i])
		variable_expander(&command->cmd_args[i++], env);
	init = command->redirects;
	while (init)
	{
		variable_expander(&((t_redir *)init->content)->file, env);
		init = init->next;
	}
	return (0);
}
