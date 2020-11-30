/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:35:20 by wscallop          #+#    #+#             */
/*   Updated: 2019/10/01 21:18:48 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	size_t	index;
	char	*str_0;

	index = 0;
	while (str[index] != '\0')
		index++;
	if (index > index + 1)
		return (0);
	str_0 = (char *)malloc(sizeof(char) * index + 1);
	if (str_0)
	{
		index = 0;
		while (str[index] != '\0')
		{
			str_0[index] = str[index];
			index++;
		}
		str_0[index] = '\0';
	}
	return (str_0);
}
