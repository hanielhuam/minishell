/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_meta_caracters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:08:47 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/19 23:38:06 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_meta_caracters(void)
{
	static char	*caracters[10] = {
		HEREDOC,
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

t_token	compare_meta_caracters_tokens(char *input)
{
	t_token	*tokens;

	tokens = get_meta_caracteres_tokens();
	return (compare_with_oneof_tokens(input, tokens));
}

t_token	*get_meta_caracteres_tokens(void)
{
	static t_token	tokens[10] = {
	{HEREDOC, TK_HEREDOC, NULL},
	{REDIRECT_IN, TK_REDIRECT_IN, NULL},
	{REDIRECT_OUT_OUT, TK_REDIRECT_OUT_OUT, NULL},
	{REDIRECT_OUT, TK_REDIRECT_OUT, NULL},
	{AND, TK_AND, NULL},
	{OR, TK_OR, NULL},
	{PIPE, TK_PIPE, NULL},
	{OPEN_PARENTH, TK_OPEN_PARENTH, NULL},
	{CLOSE_PARENTH, TK_CLOSE_PARENTH, NULL},
	{0, TK_NO_TYPE, NULL}
	};

	return (tokens);
}
