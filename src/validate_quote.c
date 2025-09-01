/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:38:02 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/08/31 21:48:54 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*first_quote_occurrence(char *input)
{
	char	*is_double;
	char	*is_single;

	is_double = ft_strchr(input, '\"');
	is_single = ft_strchr(input, '\'');
	if (!is_single)
		return (is_double);
	else if (is_double && is_double < is_single)
		return (is_double);
	return (is_single);
}

int	validate_quotes(char *input)
{
	char	*first_quote;
	char	*second_quote;

	first_quote = first_quote_occurrence(input);
	if (!first_quote)
		return (0);
	second_quote = ft_strchr(first_quote + 1, first_quote[0]);
	if (!second_quote)
		return (1);
	return (validate_quotes(second_quote + 1));
}
