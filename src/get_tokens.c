/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:52:36 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:44:45 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	**get_tokens(char *input)
{
	char	*process_input;
	t_list	**tokens;

	tokens = safe_malloc(1, sizeof(t_list *), "Error when malloc token list\n");
	if (!tokens)
		return (NULL);
	process_input = pre_process_input(input);
	if (!process_input)
		return (NULL);
	free(process_input);
	return (tokens);
}
