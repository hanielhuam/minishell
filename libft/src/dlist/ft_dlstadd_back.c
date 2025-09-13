/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:29:06 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/12 21:03:32 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlsit.h"

void	ft_dlstadd_back(t_dlsit **list, t_dlsit *new)
{
	t_dlist	*temp;

	if (!new)
		return ;
	temp = ft_dlstlast(list);
	if (temp)
	{
		temp->next = new;
		new->befor = temp;
	}
	else
		*list = new;
}
/*
#include <stdio.h>

int	*newint_point(int nu)
{
	int	*nup;

	nup = ft_calloc(1, sizeof(int));
	*nup = nu;
	return (nup);
}

void	print_t_dlsit(t_dlsit *element)
{
	printf("element->index = %d\n", element->index);
	printf("element->before = %p\n", element->before);
	printf("element->next = %p\n", element->next);
	printf("element->content = %d\n", *((int *)element->content));
}

void	print_dlsit(t_dlsit **list)
{
	t_dlsit	*temp;

	print_t_dlsit(*list);
	temp = (*list)->next;
	while (temp != *list)
	{
		printf("\n");
		print_t_dlsit(temp);
		temp = temp->next;
	}
	printf("\n");
}

int	main(void)
{
	t_dlsit	**list;
	t_dlsit *tmp;

	tmp = ft_dlstnew(newint_point(42));
	list = &tmp;
	printf("primeiro print\n");
	print_dlsit(list);
	ft_dlstadd_back(list, ft_dlstnew(newint_point(24)));
	printf("segundo print\n");
	print_dlsit(list);
	ft_dlstadd_back(list, ft_dlstnew(newint_point(84)));
	printf("terceiro print\n");
	print_dlsit(list);
	return (0);
}*/
