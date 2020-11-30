/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:14:34 by wscallop          #+#    #+#             */
/*   Updated: 2019/09/24 15:47:28 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*tmp;

	lst = *alst;
	if (alst && *alst && del)
	{
		while (lst)
		{
			tmp = lst->next;
			ft_lstdelone(&lst, del);
			lst = tmp;
		}
		*alst = NULL;
	}
}
