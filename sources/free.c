/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:05:06 by wscallop          #+#    #+#             */
/*   Updated: 2020/11/30 21:33:57 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

/*
**		Функция освобождения памяти структуры t_lst
*/

void	rmlst(t_lst *list)
{
	t_lst *tmp;

	while (list)
	{
		tmp = list;
		ft_strdel(&list->cont);
		list = list->next;
		free(tmp);
	}
}

/*
**		Функция освобождения памяти структуры t_room
*/

void	rmrooms(t_room **rooms, int len)
{
	t_room	*tmp;
	int		i;

	i = 0;
	while (i < len)
	{
		tmp = rooms[i];
		free(rooms[i++]->name);
		free(tmp);
	}
	free(rooms);
}

/*
**		Функция освобождения памяти структуры массива в структуре t_lem
*/

void	rmmatrix(t_lem *lem)
{
	int j;

	j = 0;
	while (j < lem->num_of_rooms)
		free(lem->matrix[j++]);
	free(lem->matrix);
}

/*
**		Функция освобождения памяти структуры t_lem
*/

void	rmlem(t_lem *lem)
{
	if (lem->rooms)
		rmrooms(lem->rooms, lem->num_of_rooms);
	if (lem->matrix)
		rmmatrix(lem);
	free(lem);
}

/*
**		Функция освобождения памяти структуры t_lst_paths
*/

void	rmpaths(t_lst_paths *paths)
{
	t_lst_paths	*tmp1;
	t_path		*tmp2;

	while (paths)
	{
		tmp1 = paths;
		free(paths->path->rooms);
		tmp2 = paths->path;
		paths = paths->next;
		free(tmp2);
		free(tmp1);
	}
}
