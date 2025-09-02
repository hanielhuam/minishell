/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:24:00 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:13:41 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser(t_shell *shell, char *input)
{
	t_list		**tokens;

	tokens = get_tokens(input);
	if (!tokens)
		return (-1);
	shell->tree = build_tree(tokens);
	del_token_list(tokens);
	if (!shell->tree)
		return (-1);
	return (0);
}
