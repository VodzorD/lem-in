/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 21:21:05 by wscallop          #+#    #+#             */
/*   Updated: 2020/12/01 16:03:37 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

/*
**			Функция нахождения совпадения имен комнат.
**
**		Вывод: индекс комнаты, совпавшей по имени
*/

static inline int	get_cur(t_lem *lem, t_room **queue)
{
	int cur;
	int i;

	cur = 0;
	i = 0;
	while (i < lem->num_of_rooms)
	{
		if (lem->rooms[i]->name == queue[0]->name)
			cur = i;
		i++;
	}
	return (cur);
}

/*
**			Функция заполнения массива нулями для его дальнейшей
**				реализации.
*/

static inline int	uzero(int *used, int size)
{
	int i;

	i = 0;
	while (i < size)
		used[i++] = 0;
	return (0);
}

/*
**			Алгоритм прохождения графа  ширину
**
**		1. Инициализация переменных (массив used задаем величиной
**				кол-ва комнат [нод] в графе для отметки пройденых
**				комнат)
**		2. Выделяем память для очереди (queue), массива used (flag = 0
**				[см. uzero()])
**		3. Для первого (нулевого) элемента массива used задаем значение,
**				рваное нулю. Одновременно с этим задаем для первого элемента
**				очереди (queue), оно равно комнате входа
**		4. Запускаем цикл прохода графа
**		5. Освобождаем память очереди (см. qfree())
*/

int					bfs(t_lem *lem)
{
	t_room	**queue;
	int		used[lem->num_of_rooms];
	int		cur;
	int		flag;
	int		i;

	queue = newqueue(lem->num_of_rooms);
	flag = uzero(used, lem->num_of_rooms);
	used[flag] = qin(queue, lem->num_of_rooms, lem->rooms[flag]);
	while (queue[0])
	{
		cur = get_cur(lem, queue);
		flag += (queue[0] == lem->rooms[lem->num_of_rooms - 1]);
		qrm(queue, lem->num_of_rooms);
		i = -1;
		while (++i < lem->num_of_rooms)
			if (lem->matrix[cur][i] && !used[i])
			{
				used[i] = qin(queue, lem->num_of_rooms, lem->rooms[i]);
				lem->rooms[i]->steps = lem->rooms[cur]->steps + 1;
			}
	}
	qfree(queue, lem->num_of_rooms);
	return (flag);
}
