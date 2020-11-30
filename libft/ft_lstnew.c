/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 20:16:21 by wscallop          #+#    #+#             */
/*   Updated: 2019/09/24 18:07:00 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list)
	{
		if (content != NULL)
		{
			if ((list->content = malloc(content_size)))
				ft_memcpy(list->content, content, content_size);
			else
			{
				free(list);
				return (NULL);
			}
			list->content_size = content_size;
		}
		else
		{
			list->content = NULL;
			list->content_size = 0;
		}
		list->next = NULL;
		return (list);
	}
	return (NULL);
}
