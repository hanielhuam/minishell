/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_entitys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:44:50 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/16 20:52:41 by hmacedo-         ###   ########.fr       */
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

static char	**get_types_char(void)
{
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

	return (types);
}

void	show_t_token(void *content)
{
	t_token	*token;

	token = content;
	show_token_or_subtoken(get_types_char(), token);
}

void	show_tree(t_tree *tree, int space)
{
	int	i;

	if (!tree)
		return ;
	space += 10;
	show_tree(tree->right, space);
	i = 10;
	while (i < space)
	{
		write(1," ", 1); 
		i++;
	}
	ft_printf("%s\n", get_types_char()[((t_data_tree *)tree->content)->type]);
	show_tree(tree->left, space);
}

void	show_subtree(void *content)
{
	t_data_tree	*node;

	node = content;
	if (node->type == TK_SUBSHELL)
	{
		ft_printf("begin subtree:\n");
		show_tree(*node->subtree, 0);
		ft_printf("end subtree:\n");
		ft_treeiter(*node->subtree, show_subtree);
	}
}
