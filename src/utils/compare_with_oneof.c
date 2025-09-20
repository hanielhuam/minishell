/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_with_oneof.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 20:43:33 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/19 23:32:23 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*compare_with_oneof(char *str, char **strings)
{
	while (*strings)
	{
		if (!ft_strncmp(str, *strings, ft_strlen(*strings)))
			return (*strings);
		strings++;
	}
	return (NULL);
}

t_token	compare_with_oneof_tokens(char *str, t_token *tokens)
{
	while (tokens->str)
	{
		if (!ft_strncmp(str, tokens->str, ft_strlen(tokens->str)))
			return (*tokens);
		tokens++;
	}
	return (*tokens);
}
