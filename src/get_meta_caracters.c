/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_meta_caracters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:08:47 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/05 21:36:32 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_meta_caaracters(void)
{
	char	caracters[10][2];

	caracters[0] = REDIRECT_IN;
	caracters[1] = HERE_DOC;
	caracters[2] = REDIRECT_OUT;
	caracters[3] = REDIRECT_OUT_OUT;
	caracters[4] = PIPE;
	caracters[5] = AND;
	caracters[6] = OR;
	caracters[7] = OPEN_PARENTH;
	caracters[8] = CLOSE_PARENTH;
	caracters[10] = NULL;
	return (caracters);
}
