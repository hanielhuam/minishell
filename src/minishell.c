/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:29:49 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/08/26 18:39:17 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	begin_loop(t_shell *shell)
{
	char	*input;

	if (!get_input(&input))
		parser(shell, input);
	destroy_shell(shell);
}

static void	start_shell(char **env)
{
	t_shell	*shell;

	shell = safe_malloc(1, sizeof(t_shell *), "Error when alloc t_shell\n");
	if (!shell)
		exit(EXIT_FAILURE);
	shell->env = get_env_list(env);
	if (!shell->env)
	{
		free(shell);
		exit(EXIT_FAILURE);
	}
	command_env(shell->env);
	begin_loop(shell);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	start_shell(env);
	return (0);
}
