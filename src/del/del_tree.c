/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:11:36 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/17 21:18:01 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_t_tree(void *content)
{
	t_data_tree	*data;

	data = content;
	if (data->type == TK_SUBSHELL)
		dell_tree(data->subtree);
	free(data);
}

void	dell_tree(t_tree **tree)
{
	ft_treeclear(tree, del_t_tree);
	free(tree);
}
