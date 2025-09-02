/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:24:00 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/01 21:20:49 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	**get_tokens(char *input)
{
	char	*process_input;
	t_list	**tokens;

	tokens = safe_malloc(1, sizeof(t_list *), "Error when malloc token list\n");
	if (!tokens)
		return (NULL);
	process_input = pre_process_input(input);
	if (!process_input)
		return (NULL);
	return (tokens);
}

int	parser(t_shell *shell, char *input)
{
	t_list		**tokens;

	tokens = get_tokens(input);
	if (!tokens)
		return (-1);
	shell->tree = build_tree(tokens);
	if (!shell->tree)
	{
		del_token_list(tokens);
		return (-1);
	}
	return (0);
}
