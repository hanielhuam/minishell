/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_t_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:30:56 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/19 20:34:11 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir	*creat_t_redir(void)
{
	t_redir	*redir;

	redir = safe_malloc(1, sizeof(t_redir), "Error when alloc t_redit\n");
	if (!redir)
		return (NULL);
	return (redir);
}
