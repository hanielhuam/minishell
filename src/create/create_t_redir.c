/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_t_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:30:56 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/22 20:55:36 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir	*create_t_redir(void)
{
	t_redir	*redir;

	redir = safe_malloc(1, sizeof(t_redir), "Error when alloc t_redit\n");
	if (!redir)
		return (NULL);
	return (redir);
}

t_redir	*create_t_redir_by_token(t_dlist *token)
{
	t_redir	*redir;

	redir = create_t_redir();
	redir->type = ((t_token *)token->content)->type;
	if (redir->type == TK_HEREDOC)
	{
		redir->eof = ft_strdup(((t_token *)token->next->content)->str);
		if (redir->eof)
			return (redir);
		show_error("Error when alloc eof string on t_redirect\n");
		free(redir);
		return (NULL);
	}
	redir->file = ft_strdup(((t_token *)token->next->content)->str);
	if (redir->file)
		return (redir);
	show_error("Error when alloc file string on t_redirect\n");
	free(redir);
	return (NULL);
}

int	redirect_chain(t_dlist **redirects, t_dlist *token)
{
	t_dlist	*new;
	t_redir	*redir;

	redir = create_t_redir_by_token(token);
	if (!redir)
		return (-1);
	new = ft_dlstnew(redir);
	if (!new)
	{
		del_t_redirect(redir);
		return (-1);
	}
	ft_dlstadd_back(redirects, new);
	return (0);
}
