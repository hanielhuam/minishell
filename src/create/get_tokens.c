/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:52:36 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/16 21:27:50 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*create_token(char *str, t_dlist *token_before)
{
	char	*dup;
	t_toke	*token;

	(void)token_before;
	dup = ft_strdup(str);
	if (!dup)
	{
		show_error("Error when duplicate str to create token\n");
		return (NULL);
	}
	token = is_meta_caracter_token(dup);
	if (token)
	{
		token = creat_t_token(dup, token->t_tok_type);
		if (!token)

	}

}

static t_dlist	**build_token_list(char **input_split)
{
	t_dlint	*temp;
	t_dlist	**tokens;

	tokens = safe_malloc(1, sizeof(t_dlist *), "Error when malloc token list\n");
	if (!tokens)
		return (NULL);
	while (*input_split)
	{
		temp = create_token(*input, ft_dlstlast(*tokens));
		if (!temp)
		{
			dell_token_list(tokens);
			return (NULL);
		}
		ft_dlstadd_back(tokens, temp);
	}
	return (tokens);
}

t_dlist	**get_tokens(char *input)
{
	char	*process_input;
	char	**input_split;
	t_dlist	**tokens;

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
