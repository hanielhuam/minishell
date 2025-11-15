/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_processor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:54:53 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/15 17:49:23 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_processor(t_tree *node, t_shell *shell, int dir)
{
	int		fds[2];
	t_pipe	*pipe;

	if (pipe(fds))
	{
		show_error("Error when open pipe\n");
		return (-1);
	}
	pipe = create_t_pipe(fds[0], fds[1]);
	if (!pipe)
	{
		close(fds[0]);
		close(fds[1]);
		return (-1);
	}
	if (config_pipes(node, pipe, dir))
	{
		free(pipe);
		close(fds[0]);
		close(fds[1]);
		return (-1);
	}
	return (0);
}
