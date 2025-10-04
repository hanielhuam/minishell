/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_subshell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 20:35:46 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/03 21:25:05 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	validate_subshell(t_dlist *tokens)
{
	int	diferent_tokens;

	diferent_tokens = 0;
	while (tokens)
	{
		if (((t_token *)tokens->content)->type == TK_SUBSHELL)
		{
			if (!validate_subshell(*(((t_token *)tokens->content)->subshell)))
				return (0);
		}
		else
			diferent_tokens++;
		tokens = tokens->next;
	}
	if (!diferent_tokens)
		show_error("Syntax Error: don't allow only subshell inside subshel\n");
	return (diferent_tokens);
}
