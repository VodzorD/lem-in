/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:52:25 by wscallop          #+#    #+#             */
/*   Updated: 2019/09/24 16:04:59 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int		ft_numlen(long long n)
{
	int		index;

	index = 1;
	while (n >= 10)
	{
		index++;
		n /= 10;
	}
	return (index);
}

char			*ft_itoa(int n)
{
	int			len;
	char		*str;
	int			fl;
	long long	nu;

	nu = n;
	fl = ((nu < 0) ? 1 : 0);
	nu *= ((nu < 0) ? -1 : 1);
	len = ft_numlen(nu) + fl;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str)
	{
		if (fl == 1)
			str[0] = '-';
		str[len--] = '\0';
		while (nu >= 10)
		{
			str[len] = nu % 10 + '0';
			nu /= 10;
			len--;
		}
		str[len] = nu + '0';
		return (str);
	}
	return (NULL);
}
