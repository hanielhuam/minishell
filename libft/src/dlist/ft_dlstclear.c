/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:07:46 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/09/12 23:35:19 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlstclear(ft_dlist **list, void (*del)(void *))
{
	ft_dlist	*temp;

	while (*list)
	{
		temp = (*list)->next;
		ft_dlstdelone(*list, del);
		*list = temp;
	}
	*list = NULL;
}

#include <stdio.h>

int	*newint_point(int nu)
{
	int	*nup;

	nup = ft_calloc(1, sizeof(int));
	*nup = nu;
	return (nup);
}

void	print_ft_dlist(ft_dlist *element)
{
	printf("element->before = %p\n", element->before);
	printf("element->next = %p\n", element->next);
	printf("element->content = %d\n", *((int *)element->content));
}

void	prinft_dlist(ft_dlist **list)
{
	ft_dlist	*temp;

	if (!list || !*list)
	{
		printf("list está nula\n");
		return ;
	}
	print_ft_dlist(*list);
	temp = (*list)->next;
	while (temp != *list)
	{
		printf("\n");
		print_ft_dlist(temp);
		temp = temp->next;
	}
	printf("\n");
}

void	del_stck(void * content)
{
	free(content);
}

int	main(void)
{
	ft_dlist	**list;
	ft_dlist *tmp;

	tmp = ft_dlstnew(newint_point(42));
	list = &tmp;
	ft_dlstadd_front(list, ft_dlstnew(newint_point(24)));
	ft_dlstadd_back(list, ft_dlstnew(newint_point(84)));
	prinft_dlist(list);
	ft_dlstclear(list, del_stck);
	printf("depois da ft_clear\n");
	prinft_dlist(list);
	return (0);
}
