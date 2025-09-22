/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 19:44:05 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/21 18:36:59 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show_error(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
}

void	syntax_error(char *err_msg, char *etc)
{
	show_error("sintax error: ");
	show_error(err_msg);
	show_error(etc);
	show_error("\n");
}
