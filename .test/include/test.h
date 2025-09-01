/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:56:48 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/08/22 20:08:34 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H

# include <stdint.h>
# include <inttypes.h>
# include <stdarg.h>
# include <stddef.h>
# include <setjmp.h>
# include <cmocka.h>
# include "minishell.h"

int		run_get_imput_test(void);
char	*__wrap_readline(const char *pronpt);
void	__wrap_add_history(const char *line);

#endif
