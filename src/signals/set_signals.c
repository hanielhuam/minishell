/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:07:14 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/30 19:52:02 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

static void	sigint_redsplay(int signalnum)
{
	(void)signalnum;
	redisplay_on_new_line();
	set_exit_code(130);
}

void	set_signals_readline(void)
{
	signal(SIGINT, sigint_redsplay);
	signal(SIGQUIT, SIG_IGN);
}
