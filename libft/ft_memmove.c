/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:43:16 by wscallop          #+#    #+#             */
/*   Updated: 2019/09/17 22:12:24 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ar;
	unsigned char	*gr;
	size_t			index;

	ar = (unsigned char *)dst;
	gr = (unsigned char *)src;
	index = 0;
	if (!ar && !gr)
		return (NULL);
	if (ar > gr && len)
		while (len-- > 0)
			ar[len] = gr[len];
	else if (ar <= gr && len)
		while (index < len)
		{
			ar[index] = gr[index];
			index++;
		}
	return (ar);
}
