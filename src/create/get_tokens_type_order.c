/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_type_order.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:18:02 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/07 20:56:52 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	type_value(t_tok_type type)
{
	int			value;
	int			j;
	t_tok_type	(*types)[5];

	types = get_tokens_type_order();
	value = 0;
	while (types[value][0] != TK_NO_TYPE)
	{
		j = 0;
		while (types[value][j] != TK_NO_TYPE)
		{
			if (type == types[value][j])
				return (value);
			j++;
		}
		value++;
	}
	return (0);
}

t_tok_type	(*get_tokens_type_order(void))[5]
{
	static t_tok_type types[8][5] = {
		{TK_FILE_IN, TK_DELIMITER, TK_FILE_OUT, TK_FILE_OUT_OUT, TK_NO_TYPE},
		{TK_ARGUMENT, TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE},
		{
			TK_REDIRECT_IN, TK_HEREDOC, TK_REDIRECT_OUT, TK_REDIRECT_OUT_OUT,
			TK_NO_TYPE
		},
		{TK_COMMAND, TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE},
		{TK_PIPE, TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE},
		{TK_SUBSHELL, TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE},
		{TK_AND, TK_OR, TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE},
		{TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE, TK_NO_TYPE}
	};

	return (types);
}

t_dlist	*compare_token_value(t_dlist *max, t_dlist *comp)
{
	if (type_value(((t_token *)max->content)->type) > \
			type_value(((t_token *)comp->content)->type))
		return (max);
	return (comp);
}
