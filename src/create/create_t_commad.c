/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_t_commad.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:14:32 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/19 18:56:48 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*create_t_command(void)
{
	t_command	*command;

	command = safe_malloc(1, sizeof(t_command), "Error when alloc t_command\n");
	if (!command)
		return (NULL);
	return (command);
}

t_command	*create_command_by_token(t_dlist *token)
{
	
}
