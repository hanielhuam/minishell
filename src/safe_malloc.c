/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 20:30:56 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/08/25 20:44:06 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*safe_malloc(size_t nmemb, size_t size, char *err_mensage)
{
	void	*ptr;

	ptr = ft_calloc(nmemb, size);
	if (!ptr)
		show_error(err_mensage);
	return (ptr);
}
