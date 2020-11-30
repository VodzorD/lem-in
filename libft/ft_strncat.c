/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:47:58 by wscallop          #+#    #+#             */
/*   Updated: 2019/09/18 21:46:40 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *array, const char *grid, size_t n)
{
	size_t	index;
	size_t	flag;

	index = 0;
	flag = 0;
	while (array[index] != '\0')
		index++;
	while (grid[flag] != '\0' && flag != n)
	{
		array[index] = grid[flag];
		flag++;
		index++;
	}
	array[index] = '\0';
	return (array);
}
