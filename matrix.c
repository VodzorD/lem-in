/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:44:00 by wscallop          #+#    #+#             */
/*   Updated: 2020/11/30 22:04:45 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

/*
**			Функция поиска элемента 'a'
**
**		Элемент 'a' - тот, который стоит перед '-' в информации о
**		соединении комнаты.
**		Функция находит его имя, выделяет память для него и отправляет его на
**		вывод
*/

static char			*get_a(char *s)
{
	char	*a;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[len] != '-')
		len++;
	a = (char *)ft_memalloc(sizeof(char) * len + 1);
	while (i < len)
	{
		a[i] = s[i];
		i++;
	}
	a[i] = 0;
	return (a);
}

/*
**			Функция поиска элемента 'b'
**
**		Элемент 'b' - тот, который стоит после '-' в информации о
**		соединении комнаты.
**		Функция находит его имя, выделяет память для него и отправляет его на
**		вывод
*/

static char			*get_b(char *s)
{
	char	*b;
	int		start;
	int		len;
	int		i;

	start = 0;
	i = 0;
	while (s[start++] != '-');
	len = 0;
	while (s[len++ + start]);
	b = (char *)ft_memalloc(sizeof(char) * len + 1);
	while (s[start])
		b[i++] = s[start++];
	b[i] = 0;
	return (b);
}

/*
**			Функция нахождения порядкого намера комнаты
**			по ее имени
**
**		Сравнение идет при помощи функции ft_strcmp()
**		библиотеки libft
*/

static inline int	get_coord(t_lem *lem, char *s)
{
	int	k;

	k = -1;
	while (++k < lem->num_of_rooms)
		if (!ft_strcmp(lem->rooms[k]->name, s))
			return (k);
	return (-1);
}

/*
**			Функция заполщнения матрицы соединений
**
**		На пересечении i и j ствиться 1 и, соответственно 0
**		на линии i и i (или j и j) (комната может быть соединена сама с
**		собой, но мы обозначаем это соединение как не существующее)
*/

static inline void	fill(int **m, int j, int i)
{
	m[j][i] = 1;
	m[i][j] = 1;
	m[i][i] = 0;
	m[j][j] = 0;
}

/*
**			Функция заполнения матрицы соединений
**
**		В структуре t_lst беруться инф-ия об пересечении, осуществяется
**		ее проверка, затем получаем информацию об из координатах и заносим ее
**		в матрицу пересечений. Процедура поторяется, пока есть пересечения
**
*/

int					fill_matrix(t_lem *lem, t_lst *list)
{
	char	*a;
	char	*b;
	int		j;
	int		i;

	while (list)
	{
		if (list->l)
		{
			a = get_a(list->cont);
			b = get_b(list->cont);
			if (!check_rooms(a, b, lem))
				return (0);
			j = get_coord(lem, a);
			i = get_coord(lem, b);
			ft_strdel(&a);
			ft_strdel(&b);
			fill(lem->matrix, j, i);
		}
		list = list->next;
	}
	return (1);
}
