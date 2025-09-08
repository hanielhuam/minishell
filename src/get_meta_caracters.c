/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_meta_caracters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:08:47 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/07 18:51:38 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_meta_caracters(void)
{
	static char	*caracters[10] = {
		HERE_DOC,
		REDIRECT_IN,
		REDIRECT_OUT_OUT,
		REDIRECT_OUT,
		AND,
		OR,
		PIPE,
		OPEN_PARENTH,
		CLOSE_PARENTH,
		NULL
	};
	return (caracters);
}

char	*compare_meta_caracters(char *input)
{
	char	**caracters;

	caracters = get_meta_caracters();
	return (compare_with_oneof(input, caracters));
}
