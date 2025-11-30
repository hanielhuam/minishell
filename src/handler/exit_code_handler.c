/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 19:17:25 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/11/30 19:23:09 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*get_exit_code(void)
{
	static int	status[1] = {0};

	return (status);
}

void	set_exit_code(int exit_code)
{
	int	*status;

	status = get_exit_code();
	*status = exit_code;
}
