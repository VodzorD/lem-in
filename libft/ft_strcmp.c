/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:08:23 by wscallop          #+#    #+#             */
/*   Updated: 2019/09/13 15:53:54 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	size_t	index;

	index = 0;
	while (str1[index] != '\0'
	&& str2[index] != '\0' && str1[index] == str2[index])
		index++;
	return (((unsigned char *)str1)[index] - ((unsigned char *)str2)[index]);
}
