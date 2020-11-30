/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:57:17 by wscallop          #+#    #+#             */
/*   Updated: 2019/09/18 21:46:40 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *array, const char *grid)
{
	unsigned int	index;
	unsigned int	flag;

	index = 0;
	flag = 0;
	while (array[index] != '\0')
		index++;
	while (grid[flag] != '\0')
	{
		array[index] = grid[flag];
		index++;
		flag++;
	}
	array[index] = '\0';
	return (array);
}
