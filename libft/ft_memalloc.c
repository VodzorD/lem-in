/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:17:02 by wscallop          #+#    #+#             */
/*   Updated: 2019/09/24 17:59:18 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*str;

	str = (unsigned char *)malloc(sizeof(unsigned char) * size + 1);
	if (str && size <= 9223372036854775807UL)
	{
		ft_bzero((void *)str, size);
		return (str);
	}
	return (NULL);
}
