/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:26:48 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/04 16:36:42 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	read_and_write_input(int fd_out, char *delimiter)
{
	char	*buffer;
	char	*input;
	char	*temp;

	input = ft_calloc(1, sizeof(char));
	buffer = readline("> ");
	while (buffer && ft_strncmp(buffer, delimiter, ft_strlen(delimiter)))
	{
		temp = buffer;
		buffer = ft_strjoin(temp, "\n");
		free(temp);
		input = ft_strmerge(input, buffer);
		buffer = readline("> ");
	}
	if (buffer)
		free(buffer);
	if (*input && write(fd_out, input, ft_strlen(input)) < 0)
	{
		free(input);
		return (-1);
	}
	free(input);
	return (0);
}
