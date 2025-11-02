/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_t_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:09:04 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/02 16:17:19 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pipe	*create_t_pipe(int fd_in, int fd_out)
{
	*pipe = safe_malloc(1, sizeof(t_pipe), "Error when alloc t_pipe\n");
	if (!pipe)
		return (NULL);
	pipe->fd[0] = fd_in;
	pipe->fd[1] = fd_out;
	return (pipe);
}
