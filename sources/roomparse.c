/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roomparse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:53:56 by wscallop          #+#    #+#             */
/*   Updated: 2020/11/30 22:33:55 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

/*
**			Функция нахождения длинны имени комнаты
*/

static inline int	get_name_len(char *s)
{
	char	*end;

	end = s;
	while (*end != ' ')
		end++;
	return (end - s);
}

/*
**			Функция парсинга комнат
**
**		1. Считываем длину имени комнаты (см. get_name_len())
**		2. Заполнение имени комнаты и ее координат в структуру t_room
*/

void				parseroom(t_room *room, char *info)
{
	int	len;
	int	i;

	len = get_name_len(info);
	room->name = (char *)ft_memalloc(sizeof(char) * len + 1);
	i = 0;
	while (i < len)
	{
		room->name[i] = info[i];
		i++;
	}
	room->name[i++] = 0;
	while (ft_isdigit(info[i]))
		room->coord_x = room->coord_x * 10 + info[i++] - '0';
	i++;
	while (ft_isdigit(info[i]))
		room->coord_y = room->coord_y * 10 + info[i++] - '0';
}

/*
**			Функция нахождения стартовой комнаты в структуре t_lst
**			и создание этой комнаты в структуре t_room
*/

static t_room		*get_start(t_lst *list)
{
	while (list)
	{
		if (list->s && list->r)
			return (newroom(list->cont));
		list = list->next;
	}
	return (0);
}

/*
**			Функция нахождения конечной комнаты в структуре t_lst
**			и создание этой комнаты в структуре t_room
*/

static t_room		*get_end(t_lst *list)
{
	while (list)
	{
		if (list->e && list->r)
			return (newroom(list->cont));
		list = list->next;
	}
	return (0);
}

/*
**			Функция создания списка комнат
**
**		1. Находим перую комнату и ставим ее в начало списка (см. get_start)
**		2. Создаем комнаты по мере продвижения по списку структуры t_lst
**		3. Находим последнюю комнату и вставляем конец списка (см. get_end())
*/

t_room				**get_rooms(t_lst *list, int len)
{
	t_room	**rooms;
	int		i;
	t_lst	*p;

	i = 0;
	rooms = newarr(len);
	rooms[i++] = get_start(list);
	p = list;
	while (p)
	{
		if (p->r && !p->s && !p->e)
			rooms[i++] = newroom(p->cont);
		p = p->next;
	}
	rooms[i] = get_end(list);
	return (rooms);
}
