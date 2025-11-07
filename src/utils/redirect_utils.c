/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 22:59:11 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/07 19:51:46 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir	*find_last_redirect_out(t_dlist *redirects)
{
	t_redir	*out;

	redirects = ft_dlstlast(redirects);
	while (redirects)
	{
		out = (t_redir *)redirects->content;
		if (out->type == TK_REDIRECT_OUT || out->type == TK_REDIRECT_OUT_OUT)
			return (out);
		redirects = redirects->before;
	}
	return (NULL);
}

t_redir	*find_last_redirect_in(t_dlist *redirects)
{
	t_redir	*in;

	redirects = ft_dlstlast(redirects);
	while (redirects)
	{
		in = (t_redir *)redirects->content;
		if (in->type == TK_REDIRECT_IN || in->type == TK_HEREDOC)
			return (in);
		redirects = redirects->before;
	}
	return (NULL);
}

void	atribute_pipe_redirect(int in_out, t_pipe *pipe, t_redir *redir)
{
	if ((*pipe)->fds[in_out])
		close((*pipe)->fds[in_out]);
	(*pipe)->fds[in_out] = redir->fd;
}
