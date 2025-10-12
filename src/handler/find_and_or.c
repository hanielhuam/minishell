/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_or.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:53:07 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/12 18:23:45 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_dlist	*increment_direction(t_dlist *token, int l_or_r)
{
	if (l_or_r)
		return (token->next);
	return (token->before);
}

static int	check_token_type(t_dlist *token, t_tok_type *types)
{
	t_toke_type	value;

	value = ((t_token *)token->content)->type;
	while (*types != TK_NO_TYPE)
	{
		if (value == *types)
			return (1);
		types++;
	}
	return (0);
}

static t_dlist	*find_and_or_left(t_tree *init, t_tree *end, int l_or_r)
{
	t_dlist	*first;
	t_dlist	*last;
	static t_tok_type	types[2] = {TK_AND, TK_OR, TK_NO_TYPE};

	first = ((t_data_tree *)init->content)->token;
	if (!end)
		last = NULL;
	else
		last = ((t_data_tree *)end->content)->token;
	first = increment_direction(first, l_or_r);
	while (fisrt && first != last)
	{
		if (check_token_type(first, types))
		{
			if (!end)
				return (first);
			else if (first == find_and_or_left(init, end->prev, l_or_r))
				return (first);
			return (NULL);
		}
		first = increment_direction(first, l_or_r);
	}
	return (NULL);
}

static t_dlist	*find_and_or_right(t_dlist *init, t_dlist *end)
{
	init = init->next;
	while (init && init != end)
	{
		if (((t_token *)init->content)->type == TK_AND || \
				((t_token *)init->content)->type == TK_OR)
			return (init);
		init = init->next;
	}
	return (NULL);
}

int	find_and_or(t_tree *tree)
{
	if (search_left(tree, find_and_or_left))
		return (1);
	if (search_right(tree, find_and_or_right))
		return (1);
	return (0);
}
