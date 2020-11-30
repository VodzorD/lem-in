/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:25:17 by wscallop          #+#    #+#             */
/*   Updated: 2019/10/01 21:20:03 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			index;

	index = 0;
	if (!s || len + 1 < len)
		return (NULL);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str)
	{
		while (index < len && s[start] != '\0')
		{
			str[index] = s[start];
			start++;
			index++;
		}
		str[index] = '\0';
		return (str);
	}
	return (NULL);
}
