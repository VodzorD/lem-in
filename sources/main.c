/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:51:21 by wscallop          #+#    #+#             */
/*   Updated: 2020/11/30 21:39:19 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

/*
**		Мейн программы :)
*/

int		main(void)
{
	t_lst_paths	*paths;
	t_lem		*lem;

	if (!(lem = parse()))
		return (1);
	if (bfs(lem))
		print_info(lem->list);
	else
	{
		error();
		rmlst(lem->list);
		rmlem(lem);
		return (1);
	}
	rmlst(lem->list);
	paths = get_paths(lem);
	lem->rooms[0]->ant = lem->num_of_ants;
	run_ants(lem->num_of_ants, paths);
	rmpaths(paths);
	rmlem(lem);
	return (0);
}
