/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:59:10 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/04 21:52:51 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



char	*add_space_after_caracters(char *input)
{
	int		start;
	int		count;
	char	*new_input;
	char	*meta_caracters;
	char	*temp;

	count = 0;
	start = count;
	meta_caracters = get_meta_caracters();
	new_input = "";
	while (input[count])
	{
		if (input[count] == '\"' || input[count] == '\'')
		{
			ft_strjoin(temp = into_quotes(&count, &input[count]);
			
		}
		count++;
	}
	return (new_input);
}
