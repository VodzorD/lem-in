/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:39:25 by wscallop          #+#    #+#             */
/*   Updated: 2020/12/01 18:51:34 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

/*
**			Функция записи и вывода информации о завершении пути муравья
*/

static inline void	l_step(t_room *room, int *finished, t_room *end, int i)
{
	room->ant = 0;
	end->ant++;
	finished[i] = 1;
	print_step(i + 1, end->name);
}

/*
**			Функция записи и вывода информацуии о первом шаге муравья
*/

static inline void	step_f(t_path **ants, int *finished, int i, int j)
{
	if (j == ants[i]->len - 1 && finished[i] == 0)
	{
		if (ants[i]->rooms[1]->ant == 0)
		{
			ants[i]->rooms[0]->ant--;
			ants[i]->rooms[1]->ant = i + 1;
			print_step(i + 1, ants[i]->rooms[1]->name);
		}
	}
}

/*
**			Функция записи и вывода информации о шаге муравья
*/

static inline void	healper(t_path **ants, int i, int j)
{
	ants[i]->rooms[j]->ant = 0;
	ants[i]->rooms[j + 1]->ant = i + 1;
	print_step(i + 1, ants[i]->rooms[j + 1]->name);
}

/*
**			Функция отображения перемещения всех муравьев
*/

void				step(t_path **ants, int number_of_ants,
						int *fin, t_room *end)
{
	int i;
	int j;

	i = -1;
	while (++i < number_of_ants)
	{
		j = 0;
		while (++j < ants[i]->len - 1)
		{
			if (ants[i]->rooms[j]->ant == i + 1)
			{
				if (ants[i]->rooms[j + 1] != end)
				{
					if (ants[i]->rooms[j + 1]->ant == 0)
					{
						healper(ants, i, j);
						break ;
					}
				}
				else
					l_step(ants[i]->rooms[j], fin, end, i);
			}
		}
		step_f(ants, fin, i, j);
	}
}
