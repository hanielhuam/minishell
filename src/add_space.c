/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:59:10 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/07 22:06:04 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*add_space(char *input, int start, int len, char *new_input)
{
	if (len > 0)
	{
		new_input = copy_and_paste(input, start, len, new_input);
		if (!new_input)
			return (NULL);
	}
	return (ft_strmerge(new_input, ft_strdup(" ")));
}

static int	addspacer(int *count, int *start,  char *input, char **new_input)
{
	char	*temp;

	if (input[*count] == '\"' || input[*count] == '\'')
		*count = size_into_quotes(*count, &input[*count]);
	temp = compare_meta_caracters(&input[*count]);
	if (temp)
	{
		*new_input = add_space(input, *start, *count - *start, *new_input);
		if (!*new_input)
			return (1);
		*start = *count;
		*count += ft_strlen(temp);
		*new_input = add_space(input, *start, *count - *start, *new_input);
		if (!*new_input)
			return (1);
		*start = *count;
	}
	else
		(*count)++;
	return (0);
}

char	*add_space_after_caracters(char *input)
{
	int		start;
	int		count;
	char	*new_input;

	count = 0;
	start = count;
	new_input = strdup("");
	if (!new_input)
	{
		show_error("Error when alloc new_input\n");
		return (NULL);
	}
	while (input[count])
	{
		if (addspacer(&count, &start, input, &new_input))
			return (NULL);
	}
	if (start < count)
	{
		new_input = copy_and_paste(input, start, count - start, new_input);
		if (!new_input)
			return (NULL);
	}
	return (new_input);
}
