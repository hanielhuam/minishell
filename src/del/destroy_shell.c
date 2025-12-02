/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:45:42 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/01 20:57:30 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_shell(t_shell *shell)
{
	del_env_list(shell->env);
	if (shell->tree)
		dell_tree(shell->tree);
	if (shell->process)
		ft_lstclear(&shell->process, free);
	free(shell);
}

void	erase_shell(t_shell *shell)
{
	if (shell->tree)
		dell_tree(shell->tree);
	shell->tree = NULL;
	if (shell->process)
		ft_lstclear(&shell->process, free);
	shell->process = NULL;
}
