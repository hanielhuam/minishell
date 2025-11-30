/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:07:14 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/29 23:18:46 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

static void	sigint_redsplay(int signalnum)
{
	(void)signalnum;
	redisplay_on_new_line();
	// ajustar a variável global para 130
}

void	set_signals_readline(void)
{
	signal(SIGINT, sigint_redsplay);
}
