/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 21:42:16 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/25 23:08:09 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

void	signalc(int signalnum)
{
	(void)signalnum;
	ft_printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}
/*
WIFEXITED(status)
WEXITSTATUS
WIFSIGNALED
WTERMSIG
SIGINT
SIGQUIT
SIG_IGN
*/
int	get_input(char	**input)
{
	signal(SIGINT, signalc);
	*input = readline("minishell> ");
	if (!*input || !**input || is_all_space(*input))
	{
		if (*input)
			free(*input);
		return (-1);
	}
	add_history(*input);
	return (0);
}
