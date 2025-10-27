/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:44:17 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/26 22:51:40 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdarg.h>
# include "ft_printf.h"
# include "ft_tree.h"
# include "ft_list.h"
# include "ft_dlist.h"

# define REDIRECT_IN "<"
# define HEREDOC "<<"
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
	TK_FILE_IN,
	TK_HEREDOC,
	TK_DELIMITER,
	TK_REDIRECT_OUT,
	TK_REDIRECT_OUT_OUT,
	TK_FILE_OUT,
	TK_FILE_OUT_OUT,
	TK_COMMAND,
	TK_ARGUMENT,
	TK_PIPE,
	TK_AND,
	TK_OR,
	TK_OPEN_PARENTH,
	TK_CLOSE_PARENTH,
	TK_SUBSHELL,
	TK_NO_TYPE
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
	t_dlist		**subshell;
}				t_token;

typedef struct s_pipe
{
	int	pipe[2];
}		t_pipe;

typedef struct s_redir
{
	t_tok_type	type;
	char		*file;
	char		*eof;
	int			fd;
}				t_redir;

typedef struct s_command
{
	char	**cmd_args;
	char	*path;
	t_dlist	*redirects;
}			t_command;

typedef struct s_data_tree
{
	t_tok_type	type;
	t_dlist		*token;
	t_tree		**subtree;
	t_command	*command;
	t_pipe		*pipe;
}				t_data_tree;

typedef struct s_process
{
	pid_t	pid;
}			t_process;

typedef struct s_shell
{
	int		exit_code;
	t_list	**env;
	t_tree	**tree;
	t_list	*process;
}			t_shell;

int			get_input(char	**imput);
t_list		**get_env_list(char **env);
void		show_error(char *str);
void		syntax_error(char *err_msg, char *etc);
void		*safe_malloc(size_t nmemb, size_t size, char *err_mensage);
void		del_t_env(void *content);
void		del_env_list(t_list	**env_list);
void		del_t_token(void *content);
void		del_token_list(t_dlist **tokens);
void		del_split(char **split);
void		command_env(t_list **env_list);
int			parser(t_shell *shell, char *input);
void		destroy_shell(t_shell *shell);
char		*pre_process_input(char	*input);
int			validate_quotes(char *input);
int			size_into_quotes(const char *input);
int			check_size_into_quotes(const char *input);
t_dlist		**get_tokens(char *input);
t_tree		**build_tree(t_dlist *tokens);
t_token		*create_t_token(char *str, t_tok_type type);
void		executor(t_shell *shell);
char		**get_meta_caracters(void);
t_token		*get_meta_caracteres_tokens(void);
char		*add_space_after_caracters(char *input);
char		*copy_and_paste(char *src, int start, int len, char *dest);
char		*compare_with_oneof(char *str, char **strings);
t_token		compare_with_oneof_tokens(char *str, t_token *tokens);
char		*compare_meta_caracters(char *input);
t_token		compare_meta_caracters_tokens(char *input);
char		**modified_split(char const *str, char c);
int			token_list_handler(t_dlist **tokens);
int			validate_token_list(t_dlist *tokens);
t_token		is_redirect_file_token( t_token *token_before);
t_token		is_command_token(t_dlist *token_before);
int			check_unique_command(t_dlist *last_token);
int			validate_first_token(t_token *token);
int			forbidden_tokens(t_tok_type value, t_tok_type *fobidden_tokens);
int			validate_last_token(t_token *token);
int			validate_parenthesis(t_dlist *tokens);
t_dlist		*is_there_parenthesis(t_dlist *tokens);
int			validate_after_redirect_in_token(t_dlist *token);
int			validate_after_heredoc_token(t_dlist *token);
int			validate_after_redirect_out_token(t_dlist *token);
int			validate_after_redirect_out_out_token(t_dlist *token);
int			only_accept_tokens(t_tok_type value, t_tok_type *accept_tokens);
int			validate_after_file_in_token(t_dlist *token);
int			validate_after_file_out_token(t_dlist *token);
int			validate_after_delimiter_token(t_dlist *token);
int			validate_after_file_out_out_token(t_dlist *token);
int			validate_after_command_token(t_dlist *token);
int			validate_after_argument_token(t_dlist *token);
int			validate_after_pipe_token(t_dlist *token);
int			validate_after_and_token(t_dlist *token);
int			validate_after_or_token(t_dlist *token);
int			validate_after_open_parenthesis_token(t_dlist *token);
int			validate_after_close_parenthesis_token(t_dlist *token);
int			is_all_space(char *str);
t_dlist		**parenthesis_to_subshell_handler(t_dlist **tokens);
int			validate_subshell(t_dlist *tokens);
t_dlist		*find_close_parenthesis(t_dlist *token);
char		*join_all_words_between_tokens(t_dlist *begin, t_dlist *end);
char		*join_and_free(char *s1, char *s2);
t_dlist		*find_most_valuable_token(t_dlist *tokens);
t_dlist		*compare_token_value(t_dlist *max, t_dlist *comp);
int			type_value(t_tok_type type);
t_tok_type	**get_tokens_type_order(void);
t_dlist		*compare_token_value(t_dlist *max, t_dlist *comp);
void		show_t_token(void *content);
void		show_tree(t_tree *tree, int space);
void		show_subtree(void *content);
void		dell_tree(t_tree **tree);
void		del_t_tree(void *content);
t_tree		*create_tree_by_token(t_dlist *token);
t_data_tree	*create_t_data_tree(t_tok_type type, t_dlist *token);
int			forge_and_or_tree(t_tree *tree);
int			search(t_tree *tree, void *find, void *build);
t_dlist		*search_and_or(t_tree *init, t_tree *end, int l_or_r);
t_tree		*and_or_builder(t_tree *tree, t_dlist *token);
t_dlist		*increment_direction(t_dlist *token, int l_or_r);
int			check_token_type(t_dlist *token, t_tok_type *types);
int			forge_subshell_tree(t_tree *tree);
t_dlist		*search_subshell(t_tree *init, t_tree *end, int l_or_r);
t_tree		*subshell_builder(t_tree *tree, t_dlist *token);
int			forge_pipe_tree(t_tree *tree);
t_dlist		*search_pipe(t_tree *init, t_tree *end, int l_or_r);
t_tree		*pipe_builder(t_tree *tree, t_dlist *token);
int			forge_command_tree(t_tree *tree);
t_dlist		*search_command(t_tree *init, t_tree *end, int l_or_r);
t_tree		*command_builder(t_tree *tree, t_dlist *token);
t_tree		*create_tree_by_token_builder(t_dlist *token);
t_dlist		*search_token(t_tree *init, t_tree *end, int dir, t_tok_type *type);
t_redir		*create_t_redir(void);
t_command	*create_t_command(void);
t_command	*create_command_by_token(t_dlist *token);
t_dlist		*start_command(t_dlist *token);
t_dlist		*end_command(t_dlist *token);
int			argument_count(t_dlist *start, t_dlist *end);
void		make_args(t_dlist *start, int len, char **args);
int			is_command_delimitter(t_dlist *token);
void		del_t_redirect(void *content);
void		del_t_command(t_command *command);
int			redirect_chain(t_dlist **redirects, t_dlist *token);
t_redir		*create_t_redir_by_token(t_dlist *token);
void		show_command(void *content);
char		**get_types_char(void);
void		show_t_redir(void *content);
int			execution_command_tree(t_tree *node, t_shell *shell, int dir);
int			compare_treenode_type(t_tree *node, int count, ...);
int			and_or_processor(t_tree *node, t_shell *shell, int dir);
int			subshell_processor(t_tree *node, t_shell *shell, int dir);
int			pipe_processor(t_tree *node, t_shell *shell, int dir);
int			command_processor(t_tree *node, t_shell *shell, int dir);
int			is_builtin(t_command *command);
int			wait_check(t_tree *node);
int			wait_process(t_shell *shell);

#endif
