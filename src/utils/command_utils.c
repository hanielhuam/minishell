/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:58:57 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/23 18:03:03 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist	*start_command(t_dlist *token)
{
	if (!token)
		return (token);
	while (token->before && !is_command_delimitter(token->before))
		token = token->before;
	return (token);
}

t_dlist	*end_command(t_dlist *token)
{
	if (!token)
		return (token);
	while (token->next && !is_command_delimitter(token->next))
		token = token->next;
	return (token);
}

int	argument_count(t_dlist *start, t_dlist *end)
{
	int	count;

	if (!start || !end)
		return (-1);
	count = 0;
	while (start != end)
	{
		if (((t_token *)start->content)->type == TK_ARGUMENT)
			count++;
		start = start->next;
	}
	if (((t_token *)start->content)->type == TK_ARGUMENT)
		count++;
	return (count);
}

void	make_args(t_dlist *start, int len, char **args)
{
	int		i;

	i = 1;
	while (i < len)
	{
		if (((t_token *)start->content)->type == TK_ARGUMENT)
		{
			args[i] = ft_strdup(((t_token *)start->content)->str);
			if (!args[i])
				break;
			i++;
		}
		start = start->next;
	}
	if (i != len)
	{
		show_error("Error when alloc one of the arguments\n");
		while (i >= 0)
		{
			free(args[i]);
			args[i] = NULL;
			i--;
		}
	}
}

void	show_command(void *content)
{
	int			i;
	t_data_tree	*node;

	node = content;
	if (node->type == TK_SUBSHELL)
	{
		ft_printf("inside subtree commands\n");
		ft_treeiter(*node->subtree, show_command);
		ft_printf("outside subtree commands\n");
	}
	if (!node->command)
		return ;
	ft_printf("\n\ncommand:\ntoken_type = %s\n", get_types_char()[node->type]);
	if (node->command->cmd_args)
	{
		i = 0;
		ft_printf("command with args = ");
		while (node->command->cmd_args[i])
			ft_printf("%s ", node->command->cmd_args[i++]);
	}
	if (node->command->redirects)
		ft_printf("\nlist of redirects:\n");
	if (node->command->redirects)
		ft_dlstiter(node->command->redirects, show_t_redir);
}
