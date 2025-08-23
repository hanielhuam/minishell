/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:29:49 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/08/22 21:58:37 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*input;
	t_shell	*shell;

	(void)argc;
	(void)argv;
	t_shell->env = get_env_list(env);
	while (1)
	{
		if (!get_input(&input))
		{
			parser(shell, imput);
			free(input);
			imput = NULL;
		}
	}
	return (0);
}
