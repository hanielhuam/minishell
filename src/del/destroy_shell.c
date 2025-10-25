/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:45:42 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/24 23:54:38 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_shell(t_shell *shell)
{
	del_env_list(shell->env);
	if (shell->tree)
		dell_tree(shell->tree);
	if (shell->
	free(shell);
}
