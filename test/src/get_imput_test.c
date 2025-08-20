/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_imput_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:51:52 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/08/19 21:50:51 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
/*
static int	setup(void **state)
{
	char	*imput;

	*state = &imput;
	return (0);
}

static int	teardown(void **state)
{
	 free(*((char **)*state));
	 return (0);
}
*/

static int	get_imput_return_NULL_test(vaoid **state)
{
	char	*imput;
	int		result;

	(void)state;
	imput = NULL;
	will_return(__wrap_readline, NULL);
	result = get_imput(&imput);
	assert_int_equal(result, 1); 
}

int run_get_imput_test(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(get_imput_return_NULL)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
