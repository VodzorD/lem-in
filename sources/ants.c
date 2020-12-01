/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 22:25:28 by wscallop          #+#    #+#             */
/*   Updated: 2020/12/01 18:51:44 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

/*
**				Функция вывода максимального значения пути
**
**		За максимум берется сумма длины пройденного пути и муравьёв
*/

static inline int	get_hardes_path(t_lst_paths *paths)
{
	t_lst_paths	*p;
	int			max;

	p = paths;
	max = 0;
	while (p)
	{
		if ((p->path->len + p->path->ants_num) > max)
			max = p->path->len + p->path->ants_num;
		p = p->next;
	}
	return (max);
}

/*
**				Функция нахождения минимального пути (если их несколько)
**
**		За миниму берется максимум (см. get_hardes_path())
**
**		В отличии от максимального пути ищется не только значение пути,
**		но и ссылка на сам путь, далее найденый путь заносится в массив
**		ants[].
*/

void				many_paths(t_path **ants, int num_of_ants,
						t_lst_paths *paths)
{
	t_path		*shortest_path;
	t_lst_paths	*p;
	int			min;
	int			i;

	shortest_path = 0;
	i = -1;
	while (++i < num_of_ants)
	{
		p = paths;
		min = get_hardes_path(paths);
		while (p)
		{
			if ((p->path->len + p->path->ants_num) < min)
			{
				min = p->path->len + p->path->ants_num;
				shortest_path = p->path;
			}
			p = p->next;
		}
		ants[i] = shortest_path;
		ants[i]->ants_num++;
	}
}

/*
**				Функция инициализации пути, по которому будут идти
**				муравьи
**
**		Если путей несколько, осуществляется поиск наименьшего пути
**		(см. many_paths())
*/

static inline void	init_ants(t_path **ants, int number_of_ants,
						t_lst_paths *paths)
{
	t_lst_paths	*p;
	int			i;

	p = paths;
	if (p->next == 0)
	{
		i = 0;
		while (i < number_of_ants)
		{
			ants[i++] = paths->path;
			paths->path->ants_num++;
		}
	}
	else
		many_paths(ants, number_of_ants, paths);
}

/*
**				Функция запуска муравьев по наикратчайшему пути
**
**		1. Выделение памяти под массив пути муравьев ants[num_of_ants]
**		2. Выдиление памяти под массив муравье fin[num_of_ants]
**		3. Инициализация пути (см. init_ants())
**		4. Инициализация последний комнаты end
**		5. Запуск цикла (пока муравьи не закончатся)
**		6. Запуск прохода муравьев (см. step())
**		7. Очистка памяти 2 массивов: ants[] и fin[]
*/

void				run_ants(int num_of_ants, t_lst_paths *paths)
{
	t_path	**ants;
	int		*fin;
	t_room	*end;

	ants = (t_path**)ft_memalloc(sizeof(t_path*) * num_of_ants);
	fin = (int*)ft_memalloc(sizeof(int) * num_of_ants);
	init_ants(ants, num_of_ants, paths);
	end = paths->path->rooms[paths->path->len - 1];
	while (end->ant != num_of_ants)
	{
		step(ants, num_of_ants, fin, end);
		ft_putchar('\n');
	}
	free(ants);
	free(fin);
}
