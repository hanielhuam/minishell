/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:26:48 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/06 23:23:15 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	read_and_write_input(int fd_out, char *delimiter)
{
	char	*buffer;
	char	*input;

	buffer = ft_calloc(1, sizeof(char));
	innput = ft_calloc(1, sizeof(char));
	while (buffer && !ft_strncnp(buffer, delimiter, ft_strlen(delimiter)))
	{
		input = ft_merge(input, buffer);
		buffer = get_next_delimiter(STDIN_FILENO, delimiter);
	}
	if (buffer)
		free(buffer);
	if (!*input)
	{
		free(input);
		return (0);
	}
	if (write(fd_out, input, ft_strlen(input)) < 0)
	{
		free(input);
		return (-1);
	}
	return (0);
}
