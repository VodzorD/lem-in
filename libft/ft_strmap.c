/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:21:37 by wscallop          #+#    #+#             */
/*   Updated: 2019/09/18 21:46:40 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	index;
	char	*str;

	if (!s)
		return (NULL);
	index = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (str)
	{
		while (s[index] != '\0')
		{
			str[index] = f(s[index]);
			index++;
		}
		str[index] = '\0';
		return (str);
	}
	return (NULL);
}
