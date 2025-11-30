/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:29:49 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/29 23:08:39 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	begin_loop(t_shell *shell)
{
	char	*input;

	while (1)
	{
		input = get_input(shell);
		if (!parser(shell, input))
			executor(shell);
		free(input);
		erase_shell(shell);
	}
}

static void	start_shell(char **env)
{
	t_shell	*shell;

	shell = safe_malloc(1, sizeof(t_shell), "Error when alloc t_shell\n");
	if (!shell)
		exit(EXIT_FAILURE);
	shell->env = get_env_list(env);
	if (!shell->env)
	{
		free(shell);
		exit(EXIT_FAILURE);
	}
	begin_loop(shell);
	destroy_shell(shell);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	start_shell(env);
	return (0);
}
