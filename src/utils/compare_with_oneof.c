/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_with_oneof.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 20:43:33 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/07 18:13:36 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*compare_with_oneof(char *str, char **strings)
{
	while (*strings)
	{
		if (!ft_strncmp(str, *strings, ft_strlen(*strings)))
			return (*strings);
		strings++;
	}
	return (NULL);
}
