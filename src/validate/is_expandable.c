/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_expandable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:17:57 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/23 16:25:44 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_expandable(char **str, char **variable)
{
	char	*first_quote;
	char	*last_quote;

	first_quote = first_quote_occurrence(*str);
	if (!first_quote)
		return (1);
	while (first_quote)
	{
		last_quote = ft_strchr(first_quote + 1, first_quote[0]);
		if (first_quote < *variable && *variable < last_quote)
		{
			if (first_quote[0] == '\"')
				return (1);
			return (0);
		}
		first_quote = first_quote_occurrence(last_quote + 1);
	}
	return (1);
}
