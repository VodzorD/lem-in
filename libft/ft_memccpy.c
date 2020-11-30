/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:59:27 by wscallop          #+#    #+#             */
/*   Updated: 2019/09/18 21:46:40 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *array, const void *grid, int c, size_t n)
{
	size_t			index;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)array;
	str2 = (unsigned char *)grid;
	index = 0;
	while (index != n)
	{
		str1[index] = str2[index];
		if (str1[index] == (unsigned char)c)
			return (str1 + index + 1);
		index++;
	}
	return (NULL);
}
