/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:37:27 by wscallop          #+#    #+#             */
/*   Updated: 2019/09/18 21:43:52 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *str_0)
{
	int		index;
	int		ind_0;
	char	*st;

	st = (char *)str;
	index = 0;
	ind_0 = 0;
	while (((char *)str_0)[ind_0] != '\0' && st[index] != '\0')
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
	if (((char *)str_0)[ind_0] != '\0' && st[index] == '\0')
		return (NULL);
	return (st + index - ind_0);
}
