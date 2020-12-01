/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:15:56 by wscallop          #+#    #+#             */
/*   Updated: 2020/12/01 18:51:43 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

/*
**			Функция нахождения комнаты по ее имени
*/

int		find_this_room(char *name, t_lem *lem)
{
	int i;

	i = 0;
	while (i < lem->num_of_rooms)
		if (ft_strcmp(lem->rooms[i++]->name, name) == 0)
			return (1);
	return (0);
}

/*
**			Функция проверки существования комнат
**
**		Осуществляется поиском комнат (см. find_this_room())
**		Если одна из комнат не была найдена, то осуществяется
**		освобождение памяти основной структуры t_lem и строк
**		(см. rmlem()) имен комнат a и b
*/

int		check_rooms(char *a, char *b, t_lem *lem)
{
	if (!find_this_room(a, lem) || !find_this_room(b, lem))
	{
		rmlem(lem);
		ft_strdel(&b);
		ft_strdel(&a);
		return (0);
	}
	return (1);
}
