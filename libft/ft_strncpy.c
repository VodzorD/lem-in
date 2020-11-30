/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:26:48 by wscallop          #+#    #+#             */
/*   Updated: 2019/09/10 20:54:15 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *array, const char *grid, size_t n)
{
	size_t	index;

	index = 0;
	while (grid[index] != '\0' && index != n)
	{
		array[index] = grid[index];
		index++;
	}
	while (index != n)
	{
		array[index] = '\0';
		index++;
	}
	return (array);
}
