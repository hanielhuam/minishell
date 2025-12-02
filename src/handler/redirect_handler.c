/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:12:24 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/13 13:34:25 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h>

static int	dealwith_heredoc(t_redir *redirect)
{
	int	fds[2];

	if (pipe(fds))
	{
		show_error("Error when open hedoc pipe\n");
		return (-1);
	}
	if (read_and_write_input(fds[1], redirect->eof))
	{
		close(fds[0]);
		close(fds[1]);
		return (-1);
	}
	close(fds[1]);
	redirect->fd = fds[0];
	return (0);
}

static int	dealwith_redirect(t_redir *redirect)
{
	int fd;
	int	flags;

	flags = 0;
	if (redirect->type == TK_REDIRECT_IN)
		fd = open(redirect->file, O_RDONLY);
	else 
	{
		if (redirect->type == TK_REDIRECT_OUT)
			flags = O_WRONLY | O_CREAT | O_TRUNC;
		else
			flags = O_WRONLY | O_CREAT | O_APPEND;
		fd = open(redirect->file, flags, 0644);
	}
	if (fd < 0)
	{
		perror("Error when open file on redirect");
		return (-1);
	}
	redirect->fd = fd;
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
			error = dealwith_heredoc((t_redir *)redirects->content);
		else
			error = dealwith_redirect((t_redir *)redirects->content);
		if (error)
		{
			close_redirects(init);
			return (error);
		}
		redirects = redirects->next;
	}
	return (substitute_pipes(init, pipe));
}
