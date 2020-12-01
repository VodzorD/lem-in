/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:02:14 by wscallop          #+#    #+#             */
/*   Updated: 2020/12/01 18:51:40 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

/*
**		Функция выделения памяти для структуры t_lst
*/

t_lst	*newlst(char *cont)
{
	t_lst *list;

	if (!(list = (t_lst *)ft_memalloc(sizeof(t_lst))))
		return (NULL);
	list->cont = cont;
	return (list);
}

/*
**		Функция выделения памяти для структуры t_lem
*/

t_lem	*newlem(void)
{
	t_lem *lem;

	if (!(lem = (t_lem *)ft_memalloc(sizeof(t_lem))))
		return (NULL);
	return (lem);
}

/*
**		Функция выделения памяти двумерного массива
**		структуры t_room
*/

t_room	**newarr(int len)
{
	t_room **arr;

	if (!(arr = (t_room **)ft_memalloc(sizeof(t_room *) * len)))
		return (NULL);
	return (arr);
}

/*
**		Функция выделения памяти массива структуры t_lst
*/

t_room	*newroom(char *info)
{
	t_room *room;

	if (!(room = (t_room *)ft_memalloc(sizeof(t_room))))
		return (NULL);
	parseroom(room, info);
	return (room);
}

/*
**		Функция выделения памяти для интовой матрицы
*/

int		**newmatrix(int size)
{
	int **matrix;
	int i;

	if (!(matrix = (int **)ft_memalloc(sizeof(int *) * size)))
		return (NULL);
	i = 0;
	while (i < size)
		if (!(matrix[i++] = (int *)ft_memalloc(sizeof(int) * size)))
			return (NULL);
	return (matrix);
}
