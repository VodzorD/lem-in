/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:14:37 by wscallop          #+#    #+#             */
/*   Updated: 2019/09/24 21:24:03 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	cleanup(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		ft_memdel((void **)&lst);
		lst = tmp;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem;
	t_list	*first;

	elem = ft_lstnew(lst->content, lst->content_size);
	if (elem == NULL)
		return (NULL);
	elem = (*f)(elem);
	first = elem;
	while (lst->next)
	{
		lst = lst->next;
		elem->next = ft_lstnew(lst->content, lst->content_size);
		if (elem->next == NULL)
		{
			cleanup(first);
			return (NULL);
		}
		elem->next = (*f)(elem->next);
		elem = elem->next;
	}
	return (first);
}
