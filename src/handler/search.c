/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:06:56 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/10 23:16:23 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
static int	handler_test(t_tree *any)
{

}
*/

static int	executer(void *any)
{
	void	(*anything)(char *, int);

	anything = any;
	printf("será que vai aparecer algo lá dentro\n");
	anything("ta errado, mas ta certo\n", 2);
	printf("deu certo o test\n");
	return (0);
}

int	search_left(t_tree *tree, t_dlist *(*find)(t_dlist *, t_dlist *))
{
	(void)find;
	(void)tree;
	return (executer(ft_putstr_fd));
}

int	search_right(t_tree *tree, t_dlist *(*find)(t_dlist *, t_dlist *))
{
	(void)find;
	(void)tree;
	return (0);
}
