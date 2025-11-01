/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:12:24 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/31 23:33:31 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	substitute_pipes(t_dlist *redirects, t_pipe **pipe)
{
	t_redir	*in;
	t_dlist	*out;

	in = find_last_redirect_in(redirects);
	out = find_last_redirect_out(redirects);
	if (!in && !out)
		return (0);
	if (!*pipe)
	{
		//substituir por operação de creat_pipe e dentro dela igualar os fds a 0
		*pipe = safe_malloc(1, sizeof(t_pipe), "Error when alloc redir pipe\n");
		if (!*pipe)
			return (-1);
	}
	if (in)
	{
		if ((*pipe)->fd[0])
			close((*pipe)->fd[0]);
		(*pipe)->fd[0] = 
	}
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
