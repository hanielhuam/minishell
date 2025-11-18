/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:11:29 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/17 23:21:30 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	contain_env(t_env *env, t_list *ordered_list)
{
	while (ordered_list)
	{
		if (!ft_strncmp(env->name, ((t_env *)ordered_list->content)->name))
			return (1);
		ordered_list = ordered_list->next;
	}
	return (0);
}

static t_list	*find_next_ordered(t_list *env, t_list *ordered_list)
{
	t_list	*min;

	min = env;
	env = env->next;
	while (env)
	{
		if (ft_strncmp(min
		env = env->net;
	}
	min = ft_lstnew(mint);
	if (!min)
		show_error("Error when alloc new node on ordered env list at export\n");
	return (min);
}

static int	show_env_ordered(t_list *env)
{
	t_list	*temp;
	t_list	*ordered_list;
	int		i;

	ordered_list = NULL;
	i = 0;
	while (i < ft_lstsize(env))
	{
		temp = find_next_ordered(env, ordered_list);
		if (!temp)
			return (1);
		ft_lstadd_back(ordered_list, temp);
	}
	return (0);
}

int	command_export(t_command *command, t_list **env, int fd)
{
	if (!command->cmd_args[1])
		return (show_env_ordered(*env));
}
