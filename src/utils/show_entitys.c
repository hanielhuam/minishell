/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_entitys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 20:44:50 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/23 16:42:16 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_types_char(void)
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
	char	**types;

	token = content;
	types = get_types_char();
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
		write(1, " ", 1);
		i++;
	}
	ft_printf("%s\n", get_types_char()[((t_data_tree *)tree->content)->type]);
	show_tree(tree->left, space);
}

void	show_subtree(void *content)
{
	t_data_tree	*node;

	node = (t_data_tree *)content;
	if (node->type == TK_SUBSHELL)
	{
		ft_printf("begin subtree:\n");
		show_tree(*node->subtree, 0);
		ft_printf("end subtree:\n");
		ft_treeiter(*node->subtree, show_subtree);
	}
}

void	show_t_redir(void *content)
{
	t_redir	*redir;
	char	**types;

	redir = content;
	types = get_types_char();
	ft_printf("%s\n", types[redir->type]);
	if (redir->type == TK_HEREDOC)
		ft_printf("   delimiter: %s\n", redir->eof);
	else
		ft_printf("   file: %s\n", redir->file);
}
