/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:24:00 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/06 20:47:23 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser(t_shell *shell, char *input)
{
	t_dlist		**tokens;

	tokens = get_tokens(input);
	if (!tokens)
		return (-1);
	ft_dlstiter(*tokens, show_t_token);
	if (token_list_handler(tokens))
	{
		del_token_list(tokens);
		return (-1);
	}
	ft_printf("\n\napós a validação e manipulação da subshell\n\n");
	ft_dlstiter(*tokens, show_t_token);
	shell->tree = build_tree(*tokens);
	del_token_list(tokens);
	if (!shell->tree)
		return (-1);
	return (0);
}
