/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_t_data_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:22:08 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/07 15:35:43 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data_tree	*create_t_data_tree(t_tok_type type, t_instruction *instruction)
{
	t_data_tree	*node;

	node = safe_malloc(1, sizeof(t_data_tree), "Error when malloc data tree\n");
	if (!node)
		return (NULL);
	node->type = type;
	node->instruction = instruction;
	return (node);
}
