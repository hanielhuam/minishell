/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:26:48 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/06 17:58:23 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	read_and_write_input(int fd_out, char *delimiter)
{
	char	*buffer;
	char	*input;

	input = ft_calloc(1, sizeof(char));
	buffer = get_next_delimiter(STDIN_FILENO, "\n");
	while (buffer)
	{
		if (
		input = ft_merge(input, buffer);

	}
}
