/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:44:17 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/01 21:21:16 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "ft_printf.h"

enum	e_tok_type
{
	REDIRECT_IN,
	FILE_IN
	HERE_DOC,
	DELIMITER,
	REDIRECT_OUT,
	REDIRECT_OUT_OUT,
	FILE_OUT,
	COMMAND,
	ARGUMENT,
	PIPE,
	AND,
	OR,
	OPEN_(,
	CLOSE_)
};

typedef struct	s_env
{
	char	*name;
	char	*value;
}			t_env;

typedef struct	s_token
{
	char		*str;
	e_tok_type	type;
}				t_token;

typedef struct	s_abs_tree
{
	t_abs_tree	*prev;
	t_abs_tree	*left;
	t_abs_tree	*right;
	t_token		*token;
	void		*anything;
}				t_abs_tree;

typedef struct	s_shell
{
	t_list		**env;
	t_list		**tokens;
	t_abs_tree	**tree;
}				t_shell;

int		get_input(char	**imput);
t_list	**get_env_list(char **env);
void	show_error(char *str);
void	*safe_malloc(size_t nmemb, size_t size, char *err_mensage);
void	del_t_env(void *content);
void	del_env_list(t_list	**env_list);
void	del_t_token(voide *content);
void	del_token_list(t_list *tokens);
void	command_env(t_list **env_list);
int		parser(t_shell *shell, char *input);
void	destroy_shell(t_shell *shell);
char	*pre_process_input(char	*input);
int		validate_quotes(char *input);
void	executor(t_shell *shell);

#endif
