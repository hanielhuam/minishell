/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_meta_caracters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:08:47 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/16 17:08:44 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_meta_caracters(void)
{
	static char	*caracters[10] = {
		HERE_DOC,
		REDIRECT_IN,
		REDIRECT_OUT_OUT,
		REDIRECT_OUT,
		AND,
		OR,
		PIPE,
		OPEN_PARENTH,
		CLOSE_PARENTH,
		NULL
	};
	return (caracters);
}

char	*compare_meta_caracters(char *input)
{
	char	**caracters;

	caracters = get_meta_caracters();
	return (compare_with_oneof(input, caracters));
}

static t_token	*token_atribution(char	*caracters, t_tok_type type)
{
	t_token	*tok;

	tok->caracters = caracters;
	tok->type = type;
	return (tok);
}

t_token	*get_meta_caracteres_tokens(void)
{
	static t_token	tokens[10] = {
		token_atribution(HERE_DOC, TK_HERE_DOC),
		token_atribution(REDIRECT_IN, TK_REDIRECT_IN),
		token_atribution(REDIRECT_OUT_OUT, TK_REDIRECT_OUT_OUT),
		token_atribution(REDIRECT_OUT, TK_REDIRECT_OUT),
		token_atribution(AND, TK_AND),
		token_atribution(OR, TK_OR),
		token_atribution(PIPE, TK_PIPE),
		token_atribution(OPEN_PARENTH, TK_OPEN_PARENTH),
		token_atribution(CLOSE_PARENTH, TK_CLOSE_PARENTH),
		NULL
	};
}
