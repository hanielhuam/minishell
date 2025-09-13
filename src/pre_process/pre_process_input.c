/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_process_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:12:56 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/07 23:55:16 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*pre_process_input(char *input)
{
	if (validate_quotes(input))
	{
		show_error("syntax error: unclosd quote\n");
		return (NULL);
	}
	return (add_space_after_caracters(input));
}
