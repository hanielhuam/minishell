/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_token_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:06:14 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/21 23:24:09 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	do_nothing(t_dlist *token)
{
	(void)token;
	return (0);
}

static int	(*get_validation_function(t_dlist *token))(t_dlist *)
{
	t_tok_type	value;
	static int	(*validations[1])(t_dlist *) = {
		validate_after_redirect_in_token
	};

	value = ((t_token *)token->content)->type;
	if (value == TK_REDIRECT_IN)
		return (validations[value]);
	else
		return (do_nothing);
}

int	validate_token_list(t_dlist *tokens)
{
	if (validate_first_token(tokens->content) || \
			validate_last_token(ft_dlstlast(tokens)->content) || \
			validate_parenthesis(tokens))
		return (1);
	while (tokens)
	{
		if (get_validation_function(tokens)(tokens->next))
			return (1);
		tokens = tokens->next;
	}
	return (0);
}
