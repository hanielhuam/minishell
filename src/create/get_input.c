/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 21:42:16 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/29 23:12:41 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_input(t_shell *shell)
{
	char *input;

	set_signals_readline();
	input = readline("minishell> ");
	while (input && (!*input || is_all_space(input)))
	{
		free(input);
		input = readline("minishell> ");
	}
	if (!input)
	{
		printf("exit\n");
		end_shell(0, shell);
	}
	add_history(input);
	return (input);
}
