/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_t_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:22:30 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/22 21:07:41 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_t_redirect(void *content)
{
	t_redir	*redir;

	redir = content;
	if (redir->file)
		free(redir->file);
	if (redir->eof)
		free(redir->eof);
	free(redir);
}
