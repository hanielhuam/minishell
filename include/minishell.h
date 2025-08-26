/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:44:17 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/08/25 20:37:48 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "ft_printf.h"

typedef struct s_env
{
	char	*name;
	char	*value;
}			t_env;

typedef struct s_shell
{
	t_list	**env;
	t_list	**tokens;
}			t_shell;

int		get_input(char	**imput);
t_list	**get_env_list(char **env);
void	show_error(char *str);
void	*safe_malloc(size_t nmemb, size_t size, char *err_mensage);
void	del_t_env(void *env);
void	command_env(t_list **env_list);
void	parser(t_shell *shell, char *input);

#endif
