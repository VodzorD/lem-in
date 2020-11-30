/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 21:57:58 by wscallop          #+#    #+#             */
/*   Updated: 2020/11/30 22:22:17 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

/*
**			Функция печати шага конкретного муровья
*/

void	print_step(int id, char *name)
{
	ft_putchar('L');
	ft_putnbr(id);
	ft_putchar('-');
	ft_putstr(name);
	ft_putchar(' ');
}

/*
**			Функция печати координат комнаты
*/

void	print_room(char *name, int x, int y)
{
	ft_putstr(name);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
}

/*
**			Функция печати соединения между двумя комнатами
*/

void	print_link(char *name1, char *name2)
{
	ft_putstr(name1);
	ft_putchar('-');
	ft_putstr(name2);
	ft_putchar('\n');
}

/*
**			Функция печати информации, если это не комментарий,
**			запрещенный к выводу
*/

void	print_info(t_lst *list)
{
	while (list)
	{
		if (!list->o)
		{
			ft_putstr(list->cont);
			ft_putchar('\n');
		}
		list = list->next;
	}
	ft_putchar('\n');
}

/*
**			Функция печати информации об ошибке
*/

void	error(void)
{
	ft_putstr("ERROR\n");
}
