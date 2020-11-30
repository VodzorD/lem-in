/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:47:03 by wscallop          #+#    #+#             */
/*   Updated: 2019/09/13 15:53:54 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *str_0, size_t ln)
{
	size_t	index;
	size_t	ind_0;
	char	*st;

	st = (char *)str;
	index = 0;
	ind_0 = 0;
	while (((char *)str_0)[ind_0] != '\0' && st[index] != '\0' && index != ln)
	{
		if (st[index] == ((char *)str_0)[ind_0])
			ind_0++;
		else
		{
			if (ind_0 != 0)
			{
				index = (index - ind_0) + 1;
				ind_0 = 0;
			}
		}
		index++;
	}
	if (((char *)str_0)[ind_0] != '\0' && (st[index] == '\0' || index == ln))
		return (NULL);
	return (st + index - ind_0);
}
