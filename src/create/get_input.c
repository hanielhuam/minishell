/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_imput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 21:42:16 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/08/22 21:22:56 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_input(char	**input)
{
	*input = readline(">");
	if (!*input || !**input)
	{
		if (*input)
			free(*input);
		return (-1);
	}
	add_history(*input);
	return (0);
}
