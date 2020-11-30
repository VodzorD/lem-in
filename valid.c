/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:31:15 by wscallop          #+#    #+#             */
/*   Updated: 2020/11/30 22:47:43 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

/*
**		Функция проверки информации о количесте муравьев
*/

int		is_number_of_ants(char *s)
{
	int	i;

	i = 0;
	if (!ft_strlen(s))
		return (0);
	while (s[i++] && ft_isdigit(s[i]));
	return (s[i] ? 0 : 1);
}

/*
**		Функция проверки информации комнаты (валидна ли она)
**
*/

int		is_room(char *s)
{
	int	i;

	i = 0;
	if (s[i] && (s[i] == 'L' || s[i] == '#' || ft_isspace(s[i])))
		return (0);
	while (s[i] && s[i] != ' ')
		i++;
	if (s[i] != ' ' || !ft_isdigit(s[i + 1]))
		return (0);
	i++;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	if (s[i] != ' ' || !ft_isdigit(s[i + 1]))
		return (0);
	i++;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	return (s[i] ? 0 : 1);
}

/*
**		Функция проверки информации о соединении комнат
*/

int		is_link(char *s)
{
	int	i;

	i = 0;
	if (s[i] && (s[i] == 'L' || s[i] == '#' || ft_isspace(s[i])))
		return (0);
	while (s[i] && !ft_isspace(s[i]) && s[i] != '-')
		i++;
	if (s[i] != '-' || s[i + 1] == 'L' || s[i + 1] == '#'
										|| ft_isspace(s[i + 1]))
		return (0);
	i++;
	while (s[i] && !ft_isspace(s[i]))
		i++;
	return (s[i] ? 0 : 1);
}

int		ret(t_valid_info *inf)
{
	if (inf->rs != 1 || inf->re != 1)
	{
		free(inf);
		return (0);
	}
	if (inf->s == 1 && inf->e == 1 && inf->l > 1)
	{
		free(inf);
		return (1);
	}
	free(inf);
	return (0);
}

/*
**		Функция проверки информации после получения первичных ранных
*/

int		postvalid(t_lst *list)
{
	t_valid_info	*inf;

	inf = (t_valid_info *)ft_memalloc(sizeof(t_valid_info));
	while (list)
	{
		if (list->s && !list->r)
			inf->s++;
		if (list->e && !list->r)
			inf->e++;
		inf->l += list->l;
		inf->rs += (list->r && list->s);
		inf->re += (list->r && list->e);
		if (!list->a && !list->s && !list->e
						&& !list->r && !list->l && !list->o && !list->c)
		{
			free(inf);
			return (0);
		}
		list = list->next;
	}
	return (ret(inf));
}
