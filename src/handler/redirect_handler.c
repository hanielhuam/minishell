/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:12:24 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/06 17:58:31 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	dealwith_heredoc(t_redir *redirect)
{
	int	fds[2];

	if (pipe(fds))
	{
		show_error("Error when open hedoc pipe\n");
		return (-1);
	}
	if (read_and_write_input(fds[1], redirect->delimiter))
	{
		close(fd[0]);
		clode(fd[1]);
		return (-1);
	}
	close(fds[1]);
	resirect->fd = fds[0];
	return (0);
}

static int	substitute_pipes(t_dlist *redirects, t_pipe **pipe)
{
	t_redir	*in;
	t_redir	*out;

	in = find_last_redirect_in(redirects);
	out = find_last_redirect_out(redirects);
	if (!in && !out)
		return (0);
	if (!*pipe)
	{
		*pipe = create_t_pipe(0, 0);
		if (!*pipe)
			return (-1);
	}
	if (in)
		atribute_pipe_redirect(0, *pipe, in);
	if (out)
		atribute_pipe_redirect(1, *pipe, out);
	return (0);
}

int	stablish_redirects(t_dlist *redirects, t_pipe **pipe)
{
	t_dlist	*init;
	int		error;

	init = redirects;
	error = 0;
	while (redirects)
	{
		if (((t_redir *)redirects->content)->type == TK_HEREDOC)
			error = dealwith_heredoc(redirects);
		else
			error = dealwith_redirect(redirects);
		if (error)
		{
			close_redirects(init);
			return (error);
		}
		redirects = redirects->next;
	}
	return (substitute_pipes(init, &pipe));
}
