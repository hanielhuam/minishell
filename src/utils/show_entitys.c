/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_entitys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:44:50 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/06 20:52:40 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	show_token_or_subtoken(char **types, t_token *token)
{
	if (token->type != TK_SUBSHELL)
	{
		ft_printf("str = %s and token_type = %s\n", \
				token->str, types[token->type]);
	}
	else
	{
		ft_printf("str = %s and token_type = %s\n", \
				token->str, types[token->type]);
		ft_printf("inside subshell\n");
		ft_dlstiter(*(token->subshell), show_t_token);
		ft_printf("outside subshell\n");
	}
}

void	show_t_token(void *content)
{
	t_token		*token;
	static char	*types[16] = {
		"TK_REDIRECT_IN",
		"TK_FILE_IN",
		"TK_HEREDOC",
		"TK_DELIMITER",
		"TK_REDIRECT_OUT",
		"TK_REDIRECT_OUT_OUT",
		"TK_FILE_OUT",
		"TK_FILE_OUT_OUT",
		"TK_COMMAND",
		"TK_ARGUMENT",
		"TK_PIPE",
		"TK_AND",
		"TK_OR",
		"TK_OPEN_PARENTH",
		"TK_CLOSE_PARENTH",
		"TK_SUBSHELL"
	};

	token = content;
	show_token_or_subtoken(types, token);
}

void	show_tree(t_tree *tree, int space)
{
	int	i;

	if (!tree)
		return ;
	space += 10;
	show_tree(tree->righr, space);
	i = 10;
	while (i < space)
	{
		write(1," ", 1); 
		i++;
	}
	ft_printf(tree->);
}
