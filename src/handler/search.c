/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:06:56 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/10/11 21:31:18 by hmacedo-         ###   ########.fr       */
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

int	search_left(t_tree *start, t_tree *end, void *find, void *handler) 
{
	t_dlist	*token;
	t_dlist *(*search)(t_dlist *, t_dlist *);
	t_tree	*(*builder)(t_dlist *);

	if (!start)
		return (0);
	if (tree->left && search_left(tree->left, find, builder))
		return (1);
	else 
	{
		search = find;
		handle = handler;
		token = search(start, end);
		if (!token)
			return (0);
		tree->left = builder(token);
		if (!tree->left || search_left(tree->left, find, builder))
			return (1);
	}
}

int	search_right(t_tree *tree, t_dlist *(*find)(t_dlist *, t_dlist *))
{
	(void)find;
	(void)tree;
	return (0);
}
