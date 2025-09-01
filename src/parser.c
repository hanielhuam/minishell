/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:24:00 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/08/31 22:05:32 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser(t_shell *shell, char *input)
{
	char	*process_input;

	process_input = pre_process_input(input);
	if (!process_input)
	{
		destroy_shell(shell);
		return (-1);
	}
	return (0);
}
