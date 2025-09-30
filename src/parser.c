/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:24:00 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/29 20:12:44 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	show_t_token(void *content);

static void show_token_or_subtoken(char **types, t_token *token)
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

static void	show_t_token(void *content)
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
	shell->tree = build_tree(tokens);
	del_token_list(tokens);
	if (!shell->tree)
		return (-1);
	return (0);
}
