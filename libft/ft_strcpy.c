/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:16:37 by wscallop          #+#    #+#             */
/*   Updated: 2019/09/18 21:46:40 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *array, const char *grid)
{
	size_t	index;
	char	*str;

	str = array;
	index = 0;
	while (grid[index] != '\0')
	{
		str[index] = grid[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
