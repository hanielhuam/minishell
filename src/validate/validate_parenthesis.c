/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_parenthesis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 19:35:46 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/25 21:07:58 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist	*is_there_parenthesis(t_dlist *tokens)
{
	while (tokens)
	{
		if (((t_token *)tokens->content)->type == TK_OPEN_PARENTH || \
				((t_token *)tokens->content)->type == TK_CLOSE_PARENTH)
			return (tokens);
		tokens = tokens->next;
	}
	return (NULL);
}

static int	check_open_close_parenthesis(t_dlist *tokens)
{
	int	result;

	result = 0;
	while (tokens)
	{
		if (((t_token *)tokens->content)->type == TK_OPEN_PARENTH)
			result++;
		if (((t_token *)tokens->content)->type == TK_CLOSE_PARENTH)
			result--;
		tokens = tokens->next;
	}
	if (result)
		show_error("syntax error: the parenthesis are not evenly\n");
	return (result);
}

int	validate_parenthesis(t_dlist *tokens)
{
	t_dlist	*first;

	first = is_there_parenthesis(tokens);
	if (!first)
		return (0);
	if (((t_token *)first->content)->type == TK_CLOSE_PARENTH)
	{
		show_error("syntax error: ')' couldn`t be before '('\n");
		return (1);
	}
	if (check_open_close_parenthesis(first))
		return (1);
	return (0);
}
