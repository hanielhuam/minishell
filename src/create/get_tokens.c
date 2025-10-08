/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:52:36 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/08 19:24:28 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*create_token(char *str, t_dlist *token_before)
{
	char	*dup;
	t_token	token;

	dup = ft_strdup(str);
	if (!dup)
	{
		show_error("Error when duplicate str to create token\n");
		return (NULL);
	}
	token = compare_meta_caracters_tokens(dup);
	if (token.type != TK_NO_TYPE)
		return (create_t_token(dup, token.type));
	if (!token_before)
		return (create_t_token(dup, TK_COMMAND));
	token = is_redirect_file_token(token_before->content);
	if (token.type != TK_NO_TYPE)
		return (create_t_token(dup, token.type));
	token = is_command_token(token_before);
	if (token.type != TK_NO_TYPE)
		return (create_t_token(dup, token.type));
	else
		return (create_t_token(dup, TK_ARGUMENT));
}

static t_dlist	**build_token_list(char **input_split)
{
	t_dlist	*temp;
	t_dlist	**tokens;
	t_token	*token;

	tokens = safe_malloc(1, sizeof(t_dlist *), "Error when maloc token list\n");
	if (!tokens)
		return (NULL);
	while (*input_split)
	{
		token = create_token(*input_split++, ft_dlstlast(*tokens));
		temp = ft_dlstnew(token);
		if (!token || !temp)
		{
			if (!temp)
				show_error("Error when create list node\n");
			else
				free(temp);
			del_token_list(tokens);
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
