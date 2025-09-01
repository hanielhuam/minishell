/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_process_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:12:56 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/08/31 21:43:47 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*pre_process_input(char *input)
{
	char	*new_input;

	new_input = NULL;
	if (validate_quotes(input))
	{
		show_error("syntax error: unclosd quote\n");
		return (NULL);
	}
	ft_printf("passou da validação das aspas\n");
	return (new_input);
}
