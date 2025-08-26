/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_t_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:53:41 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/08/25 20:47:14 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_t_env(void *env)
{
	t_env	*tenv;
	
	tenv = (t_env *)env;
	free(tenv->name);
	free(tenv->value);
	free(env);
	env = NULL;
}
