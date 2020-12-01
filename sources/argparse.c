/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:58:33 by wscallop          #+#    #+#             */
/*   Updated: 2020/12/01 18:51:43 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

/*
**			Функция считывания первого параметра (по факту -
**			количества мураьев)
**
**		Параметр считываем при помощи get_next_line()
*/

static t_lst	*get_first_elem(void)
{
	t_lst	*head;
	char	*line;
	int		ret;

	head = 0;
	if ((ret = get_next_line(0, &line)))
	{
		if (ret == -1)
		{
			ft_strdel(&line);
			return (0);
		}
		head = newlst(0);
		head->cont = line;
	}
	else
	{
		ft_strdel(&line);
		return (0);
	}
	return (head);
}

/*
**			Функция считываения всех параметров, подающихся на вход
**
**		Сначала считываем первый параметр (см. get_fist_elem()), а затем
**		и остальных при помощи get_next_line()
*/

t_lst			*preparse(void)
{
	t_lst	*list;
	t_lst	*head;
	char	*line;
	int		ret;

	if (!(head = get_first_elem()))
		return (0);
	ret = 0;
	list = head;
	while ((ret = get_next_line(0, &line)))
	{
		if (ret == -1)
			return (0);
		list->next = newlst(line);
		list = list->next;
	}
	ft_strdel(&line);
	return (head);
}

/*
**			Функция подсчета количества комнат (нод) графа
**
**		Обычный счетчик
*/

int				get_number_of_rooms(t_lst *list)
{
	int	res;

	res = 0;
	while (list)
	{
		res += list->r;
		list = list->next;
	}
	return (res);
}

/*
**			Функция вывода ошибки
**
**		Выводит не только информацию об ошибке, но и
**		освобождает память структуры t_lst (см. rmlst())
*/

t_lem			*ret_error(t_lst *list, int flag_error)
{
	if (flag_error)
		error();
	rmlst(list);
	return (0);
}

/*
**			Функция парсинга данных, подоваемых на вход программы
**
**		1. Осуществляется считывание входой строки и проверки на наличие
**			муравьев в ней (см. preparse() и is_number_of_ants())
**		2. В list заносяться данные первичные данные о графе (см. marup())
**		3. Проверка первичных данных (см. postparse())
**		4. Выделяется память под lem (см. newlem())
**		5. Заполнение структуры t_lem
*/

t_lem			*parse(void)
{
	t_lst	*list;
	t_lem	*lem;

	if (!(list = preparse()) || !is_number_of_ants(list->cont))
		return (ret_error(list, 1));
	list->a = 1;
	markup(list);
	if (!postvalid(list))
		return (ret_error(list, 1));
	lem = newlem();
	lem->list = list;
	lem->num_of_ants = ft_atoi(list->cont);
	lem->num_of_rooms = get_number_of_rooms(list);
	lem->rooms = get_rooms(list, lem->num_of_rooms);
	lem->matrix = newmatrix(lem->num_of_rooms);
	if (!fill_matrix(lem, list))
		return (ret_error(list, 1));
	return (lem);
}
