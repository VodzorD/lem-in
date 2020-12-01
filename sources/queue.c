/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:35:55 by wscallop          #+#    #+#             */
/*   Updated: 2020/11/30 22:25:29 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

/*
**			Функция выделения памяти под очередь
*/

t_room	**newqueue(int size)
{
	t_room	**queue;

	queue = (t_room **)ft_memalloc(sizeof(t_room *) * size);
	return (queue);
}

/*
**			Функция заполнения очереди
*/

int		qin(t_room **queue, int size, t_room *room)
{
	int i;

	i = -1;
	while (++i < size)
		if (!queue[i])
		{
			queue[i] = room;
			return (1);
		}
	return (0);
}

/*
**		Функция удаления элемента из очереди со смещением самой очереди
*/

void	qrm(t_room **queue, int size)
{
	int i;

	i = 0;
	while (++i < size)
		queue[i - 1] = queue[i];
	queue[size - 1] = 0;
}

/*
**			Функция освобождения памяти очереди
*/

void	qfree(t_room **queue, int size)
{
	int i;

	i = 0;
	while (i < size)
		free(queue[i++]);
	free(queue);
}
