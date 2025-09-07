/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_and_paste.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 20:26:56 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/06 23:24:17 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*copy_and_paste(char *src, int start, int len, char *dest)
{
	char	*substring;
	
	substring = ft_substr(src, start, len);
	if (!substring)
	{
		free(dest);
		show_error("Error when alloc substring\n");
		return (NULL);
	}
	dest = ft_strmerge(substring, dest);
	if (!dest)
		show_error("Error when alloc merge_str\n");
	return (dest);
}
