/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_t_commad.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:14:32 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/23 15:27:21 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*create_t_command(void)
{
	t_command	*command;

	command = safe_malloc(1, sizeof(t_command), "Error when alloc t_command\n");
	if (!command)
		return (NULL);
	return (command);
}

static int	stablish_command(t_command *command, t_dlist *token)
{
	t_dlist	*end;
	char	*command_str;
	
	token = start_command(token);
	end = end_command(token);
	while (token != end)
	{
		if (((t_token *)token->content)->type == TK_COMMAND)
			break;
		token = token->next;
	}
	if (!(((t_token *)token->content)->type == TK_COMMAND))
		return (0);
	command_str = ft_strdup(((t_token *)token->content)->str);
	if (!command_str)
	{
		show_error("Error when alloc command string\n");
		return (-1);
	}
	command->path = command_str;
	return (0);
}

static int	assemble_arguments(t_command *command, t_dlist *token)
{
	int		len;
	t_dlist	*end;
	char	**args;

	if (!command->path)
		return (0);
	end = end_command(token);
	token = start_command(token);
	len = argument_count(token, end) + 1;
	args = safe_malloc(len + 1, sizeof(char *), "Error when alloc cmd_args\n");
	if (!args)
		return (-1);
	args[0] = ft_strdup(command->path);
	if (args[0])
		make_args(token, len, args);
	if (!args[0])
	{
		show_error("Error when duplicate command path or arguments\n");
		free(args);
		return (-1);
	}
	command->cmd_args = args;
	return (0);
}

static int	redirect_factory(t_command *command, t_dlist *token)
{
	t_dlist		*redirects;
	t_dlist		*end;
	t_tok_type	type;

	end = end_command(token);
	token = start_command(token);
	redirects = NULL;
	while (token != end)
	{
		type = ((t_token *)token->content)->type;
		if ((type == TK_REDIRECT_IN || type == TK_HEREDOC || \
				type == TK_REDIRECT_OUT || type == TK_REDIRECT_OUT_OUT) &&
				redirect_chain(&redirects, token))
		{
			ft_dlstclear(&redirects, del_t_redirect);
			return (1);
		}
		token = token->next;
	}
	command->redirects = redirects;
	return (0);
}

t_command	*create_command_by_token(t_dlist *token)
{
	t_command	*command;

	command = create_t_command();
	if (!(command && !stablish_command(command, token) && \
				!assemble_arguments(command, token) && \
				!redirect_factory(command, token)))
	{
		del_t_command(command);
		return (NULL);
	}
	return (command);
}
