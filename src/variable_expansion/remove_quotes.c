/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 20:30:17 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/24 16:48:35 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*remove_quote(char *str, char *quote)
{
	char	*temp;

	temp = ft_substr(str, 0, ft_strlen(str) - ft_strlen(quote));
	if (!temp)
		return (NULL);
	return (ft_strmerge(temp, ft_strdup(quote + 1)));
}

static char	*del_quotes(char *str, char q)
{
	char	*temp;
	char	*result;
	char	*quote;

	quote = ft_strchr(str, q);
	temp = remove_quote(str, quote);
	if (!temp)
		return (NULL);
	quote = ft_strchr(temp, q);
	result = remove_quote(temp, quote);
	free(temp);
	return (result);
}

char	*remove_quotes(char *str)
{
	char	*temp;
	char	*quote;
	char	*result;
	int		len;

	result = ft_strdup(str);
	if (!result)
		return (NULL);
	quote = first_quote_occurrence(result);
	while (quote)
	{
		quote = ft_strchr(quote + 1, *quote);
		len = ft_strlen(result) - ft_strlen(quote);
		temp = del_quotes(result, *quote);
		if (!temp)
			return (result);
		free(result);
		result = temp;
		if (ft_strlen(result) < 2)
			break ;
		quote = first_quote_occurrence(result + len - 1);
	}
	return (result);
}
