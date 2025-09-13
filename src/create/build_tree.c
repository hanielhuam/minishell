/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:37:26 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:10:19 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_abs_tree	**build_tree(t_list **tokens)
{
	t_abs_tree	**tree;

	(void)tokens;
	tree = safe_malloc(1, sizeof(t_abs_tree *), "Error when malloc tree\n");
	if (!tree)
		return (NULL);
	return (tree);
}
