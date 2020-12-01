/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:22:35 by wscallop          #+#    #+#             */
/*   Updated: 2020/11/30 21:47:01 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

/*
**			Фунция проверки первичных входных данных
**
**		1. Проверка на наличие комнаты (см. is_room())
**		2. Проверка на наличие соединений (см. is_link)
**		3. Проверак на наличие коментариев
**		4. Проверка на наличие обозначения комнаты start
**		5. Проверка на наличие обозначения комнаты end
**		6. Проверка на наличие коментариев, не доступных к выводу
*/

void	markup(t_lst *list)
{
	while (list)
	{
		if (is_room(list->cont))
			list->r = 1;
		else if (is_link(list->cont))
			list->l = 1;
		else if (list->cont[0] == '#' && list->cont[1] != '#')
			list->c = 1;
		else if (!ft_strcmp("##start", list->cont))
		{
			list->s = 1;
			if (list->next && is_room(list->next->cont))
				list->next->s = 1;
		}
		else if (!ft_strcmp("##end", list->cont))
		{
			list->e = 1;
			if (list->next && is_room(list->next->cont))
				list->next->e = 1;
		}
		else if (list->cont[0] == '#' && list->cont[1] == '#')
			list->o = 1;
		list = list->next;
	}
}
