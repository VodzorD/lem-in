/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:23:24 by wscallop          #+#    #+#             */
/*   Updated: 2019/09/18 21:43:52 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			index;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	index = 0;
	while (str1[index] != '\0' && str2[index] != '\0'
	&& str1[index] == str2[index] && index != n - 1)
		index++;
	if (!n)
		return (0);
	return (str1[index] - str2[index]);
}
