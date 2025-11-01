/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:12:24 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/31 21:14:23 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	stablish_redirects(t_dlist *redirects, t_pipe *pipe)
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
	return (substitute_pipes(init, pipe));
}
