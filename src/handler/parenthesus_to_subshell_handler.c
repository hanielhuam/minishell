/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesus_to_subshell_handler.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 19:22:56 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/26 21:24:27 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_dlist	*find_close_parenthesis(t_token *open)
{

}

static t_dlis	*new_subshell(t_token *subshell, t_dlist *open, t_dlist *close)
{
	t_dlist	*new;
	t_dlist **subshell_tokens;

	new = ft_dlstnew(subshell);
	subshell_tokens = ft_calloc(1, sizeof(t_dlist*));
	if (!new || subshell_tokens
}

static int	turn_into_sushell(t_token **tokens)
{
	t_token	*subshell;
	t_token *close;
	char	*subshell_inner_content;
	t_dlist *new;

	close = find_close_parenthesis(*tokens);
	subshell_inner_content = join_all_words_between_tokens(*tonkens, close);
	if (!subshell_inner_content)
		return (1);
	subshell = creat_t_toke(subshell_inner_content, TK_SUBSHELL);
	if (!subshell)
	{
		free(subshell_inner_content);
		return (1);
	}
	new = new_subshell(
}

t_dlist	**parenthesis_to_subshell_handler(t_dlit **tokens)
{
	t_dlist	*first;

	first = is_there_parenthesis(*tokens);
	if (!first)
		return (tokens);
	if (subshell_handler(&first))
	return (tokens);
}
