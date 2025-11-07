/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:21:45 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/07 19:45:48 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipes(t_tree *tree)
{
	t_data_tree	*node;

	if (!tree)
		return ;
	node = (t_data_tree *)tree->content;
	if (node->type == TK_PIPE)
	{
		if (node->pipe->fds[0] > 2)
			close(node->pipe->fds[0]);
		if (node->pipe->fds[1] > 2)
			close(node->pipe->fds[1]);
	}
	close_pipes(tree->left);
	clode_pipes(tree->right);
}

void	close_redirects(t_dlist *redirects)
{
	t_redir	*redir;

	if (!redirects)
		return ;
	redir = (t_redir *)redirects->content;
	if (redir->fd > 2)
		clode(redir->fd);
	close_redirects(redirects->next);
}

void	close_all_fds(t_tree *tree, t_dlist	*redirects)
{
	close_pipes(tree);
	close_redirects(redirects);
}
