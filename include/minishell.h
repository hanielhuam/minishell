/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:44:17 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/04 20:57:28 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "ft_printf.h"

# define REDIRECT_IN "<"
# define HERE_DOC "<<"
# define REDIRECT_OUT ">"
# define REDIRECT_OUT_OUT ">>"
# define PIPE "|" 
# define AND "&&"
# define OR "||"
# define OPEN_PARENTH "("
# define CLOSE_PARENTH ")"

typedef enum e_tok_type
{
	TK_REDIRECT_IN,
	TK_FILE_INi,
	TK_HERE_DOC,
	TK_DELIMITER,
	TK_REDIRECT_OUT,
	TK_REDIRECT_OUT_OUT,
	TK_FILE_OUT,
	TK_COMMAND,
	TK_ARGUMENT,
	TK_PIPE,
	TK_AND,
	TK_OR,
	TK_OPEN_PARENTH,
	TK_CLOSE_PARENTH
}	t_tok_type;

typedef struct s_env
{
	char	*name;
	char	*value;
}			t_env;

typedef struct s_token
{
	char		*str;
	t_tok_type	type;
}				t_token;

typedef struct s_abs_tree
{
	struct s_abs_tree	*prev;
	struct s_abs_tree	*left;
	struct s_abs_tree	*right;
	t_token				*token;
	void				*anything;
}						t_abs_tree;

typedef struct s_shell
{
	t_list		**env;
	t_list		**tokens;
	t_abs_tree	**tree;
}				t_shell;

int			get_input(char	**imput);
t_list		**get_env_list(char **env);
void		show_error(char *str);
void		*safe_malloc(size_t nmemb, size_t size, char *err_mensage);
void		del_t_env(void *content);
void		del_env_list(t_list	**env_list);
void		del_t_token(void *content);
void		del_token_list(t_list **tokens);
void		command_env(t_list **env_list);
int			parser(t_shell *shell, char *input);
void		destroy_shell(t_shell *shell);
char		*pre_process_input(char	*input);
int			validate_quotes(char *input);
t_list		**get_tokens(char *input);
t_abs_tree	**build_tree(t_list **tokens);
void		executor(t_shell *shell);
char		**get_meta_caracters(void);
char		*add_space_after_caracters(char *input);

#endif
