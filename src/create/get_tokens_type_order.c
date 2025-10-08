/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_type_order.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:18:02 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/08 17:14:28 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	type_value(t_tok_type type)
{
	int			value;
	int			j;
	t_tok_type	**types;

	types = get_tokens_type_order();
	value = 0;
	while (types[value])
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

t_tok_type	**get_tokens_type_order(void)
{
	static t_tok_type type0[5] = {
		TK_FILE_IN, TK_DELIMITER, TK_FILE_OUT, TK_FILE_OUT_OUT, TK_NO_TYPE
	};
	static t_tok_type type1[2] = {TK_ARGUMENT, TK_NO_TYPE};
	static t_tok_type type2[5] = {
		TK_REDIRECT_IN, TK_HEREDOC, TK_REDIRECT_OUT, TK_REDIRECT_OUT_OUT,
		TK_NO_TYPE
	};
	static t_tok_type type3[2] = {TK_COMMAND, TK_NO_TYPE};
	static t_tok_type type4[2] = {TK_PIPE, TK_NO_TYPE};
	static t_tok_type type5[2] = {TK_SUBSHELL, TK_NO_TYPE};
	static t_tok_type type6[3] = {TK_AND, TK_OR, TK_NO_TYPE};
	static t_tok_type *types[8] = {
		type0, type1, type2, type3, type4, type5, type6, NULL};

	return (types);
}

t_dlist	*compare_token_value(t_dlist *max, t_dlist *comp)
{
	if (type_value(((t_token *)max->content)->type) > \
			type_value(((t_token *)comp->content)->type))
		return (max);
	return (comp);
}
