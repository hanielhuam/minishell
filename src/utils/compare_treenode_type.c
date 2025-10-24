/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_treenode_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 21:12:14 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/23 23:15:19 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	compare_treenode_type(t_tree *node, int count, ...)
{
	t_tok_type	type;
	va_list		args;
	int			i;

	type = ((t_data_tree *)node->content)->type;
	va_start(args, count);
	i = 0;
	while (i < count)
	{
		if (type == va_arg(args, t_tok_type))
			return (1);
		i++;
	}
	va_end(args);
	return (0);
}
