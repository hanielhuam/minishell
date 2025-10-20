/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_most_valuable_token.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 21:19:12 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/19 19:55:06 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist	*find_most_valuable_token(t_dlist *tokens)
{
	t_dlist	*most_valuable;

	most_valuable = tokens;
	tokens = tokens->next;
	while (tokens)
	{
		if (compare_token_value(most_valuable, tokens) != most_valuable)
			most_valuable = tokens;
		tokens = tokens->next;
	}
	return (most_valuable);
}
