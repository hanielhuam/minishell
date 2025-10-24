/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_token_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:06:14 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/24 18:33:00 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	token_validation(t_dlist *token, t_dlist *next_token)
{
	t_tok_type	type;
	static int	(*validations[15])(t_dlist *) = {
		validate_after_redirect_in_token,
		validate_after_file_in_token,
		validate_after_heredoc_token,
		validate_after_delimiter_token,
		validate_after_redirect_out_token,
		validate_after_redirect_out_out_token,
		validate_after_file_out_token,
		validate_after_file_out_out_token,
		validate_after_command_token,
		validate_after_argument_token,
		validate_after_pipe_token,
		validate_after_and_token,
		validate_after_or_token,
		validate_after_open_parenthesis_token,
		validate_after_close_parenthesis_token
	};

	type = ((t_token *)token->content)->type;
	return (validations[type](next_token));
}

int	validate_token_list(t_dlist *tokens)
{
	if (validate_first_token(tokens->content) || \
			validate_last_token(ft_dlstlast(tokens)->content) || \
			validate_parenthesis(tokens))
		return (1);
	while (tokens)
	{
		if (token_validation(tokens, tokens->next))
			return (1);
		tokens = tokens->next;
	}
	return (0);
}
