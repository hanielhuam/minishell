/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesus_to_subshell_handler.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 19:22:56 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/03 20:02:24 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	manipulate_pointers(t_dlist *new, t_dlist *open, t_dlist *close)
{
	new->before = open->before;
	new->next = close->next;
	if (open->before)
		open->before->next = new;
	if (close->next)
		close->next->before = new;
	open->next->before = NULL;
	close->before->next = NULL;
	ft_dlstdelone(open, del_t_token);
	ft_dlstdelone(close, del_t_token);
}

static t_dlist	*new_subshell(t_token *subshell, t_dlist *open, t_dlist *close)
{
	t_dlist	*new;
	t_dlist **subshell_tokens;

	subshell_tokens = safe_malloc(1, sizeof(t_dlist *), \
			"Error When alloc subshell \n");
	if (!subshell_tokens)
		return (NULL);
	*subshell_tokens = open->next;
	subshell->subshell = subshell_tokens;
	new = ft_dlstnew(subshell);
	if (!new)
	{
		free(subshell_tokens);
		subshell->subshell = NULL;
		show_error("Error when alloc new token fod dubshell\n");
		return (NULL);
	}
	manipulate_pointers(new, open, close);
	return (new);
}

static t_token	*create_subshell_token(t_dlist *begin, t_dlist *close)
{
	t_token	*subshell;
	char	*subshell_inner_content;

	subshell_inner_content = join_all_words_between_tokens(begin->next, \
			close->before);
	if (!subshell_inner_content)
		return (NULL);
	subshell = create_t_token(subshell_inner_content, TK_SUBSHELL);
	if (!subshell)
	{
		free(subshell_inner_content);
		return (NULL);
	}
	return (subshell);
}

static int	turn_into_subshell(t_dlist **tokens)
{
	t_token	*subshell;
	t_dlist *close;
	t_dlist *new;

	close = find_close_parenthesis((*tokens)->next);
	subshell = create_subshell_token(*tokens, close);
	if (!subshell)
		return (1);
	new = new_subshell(subshell, *tokens, close);
	if (!new)
	{
		free(subshell);
		return (1);
	}
	*tokens = new;
	if (!parenthesis_to_subshell_handler(subshell->subshell))
		return (1);
	return (0);
}

t_dlist	**parenthesis_to_subshell_handler(t_dlist **tokens)
{
	t_dlist	*first;

	first = is_there_parenthesis(*tokens);
	if (!first)
		return (tokens);
	if (first == *tokens)
	{
		if (turn_into_subshell(tokens))
			return (NULL);
		if (!parenthesis_to_subshell_handler(tokens))
			return (NULL);
	}
	else
	{
		if (turn_into_subshell(&first))
			return (NULL);
		if (!parenthesis_to_subshell_handler(&first))
			return (NULL);
	}
	return (tokens);
}
