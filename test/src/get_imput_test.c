/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_imput_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:51:52 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/08/17 21:53:17 by hmacedo-         ###   ########.fr       */
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
	char	imput;

	(void)state;
	imput = NULL;


}
