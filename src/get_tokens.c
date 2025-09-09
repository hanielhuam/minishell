/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:52:36 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/08 17:36:00 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	**build_token_list(char **input_split)
{
	t_list **tokens;

	while (*input_split)
		ft_printf("%s\n", *input_split++);
	tokens = safe_malloc(1, sizeof(t_list *), "Error when malloc token list\n");
	if (!tokens)
		return (NULL);
	return (tokens);
}

t_list	**get_tokens(char *input)
{
	char	*process_input;
	char	**input_split;
	t_list	**tokens;

	process_input = pre_process_input(input);
	if (!process_input)
		return (NULL);
	input_split = modified_split(process_input, ' ');
	free(process_input);
	if (!input_split)
		return (NULL);
	tokens = build_token_list(input_split);
	del_split(input_split);
	if (!tokens)
		return (NULL);
	return (tokens);
}
