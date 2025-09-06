/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:59:10 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/05 23:08:31 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	addspacer(int *count, char *input, char *new_str, char **caracters)
{
	if (*input == '\"' || *input == '\'')
	{
		count += size_into_quotes(count, input);
		return (1);
	}
	else if (compare_with_oneof(input, caracters))
	{
		if (!add_space(&count, &input[count], new_str, caracters))
			return (-1);
	}
	else
	{
		count++;
		return (0);
	}
}

char	*add_space_after_caracters(char *input)
{
	int		start;
	int		count;
	char	*new_input;
	int		temp;
	char	**meta_caracters;

	meta_caracters = get_meta_caracters;
	count = 0;
	start = count;
	new_input = strdup("");
	if (!new_input)
		return (NULL);
	while (input[count])
	{
		temp = add_spacer(&count, &input[count], new_input, meta_caracters);
		if (temp < 0)
			return (NULL);
		else if (temp > 0)
			start = count;
	}
	return (new_input);
}
