/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_readline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 21:08:22 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/08/22 19:55:31 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	*__wrap_readline(const char *pronpt)
{
	(void)pronpt;
	return (char *)mock();
}

void	__wrap_add_history(const char *line)
{
	check_expected_ptr(line);
}
