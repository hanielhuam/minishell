/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:29:49 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/08/10 21:59:41 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*input;

	(void)argc;
	(void)argv;
	(void)env;
	while (1)
	{
		if (!get_input(&input))

		free(input);
	}
	return (0);
}
