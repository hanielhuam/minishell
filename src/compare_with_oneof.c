/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_with_oneof.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 20:43:33 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/06 23:24:44 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.c"

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
