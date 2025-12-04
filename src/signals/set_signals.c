/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:07:14 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/12/04 18:16:43 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

static void	sigint_redisplay(int signalnum)
{
	(void)signalnum;
	redisplay_on_new_line();
	set_exit_code(130);
}

static void	sigint_no_redisplay(int signalnum)
{
	(void)signalnum;
	new_line_no_redisplay();
}

void	set_signals_readline(void)
{
	signal(SIGINT, sigint_redisplay);
	signal(SIGQUIT, SIG_IGN);
}

void	set_signal_heredoc(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	set_signal_on_fork(void)
{
	signal(SIGINT, sigint_no_redisplay);
	signal(SIGQUIT, SIG_IGN);
}
