/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:13:06 by wscallop          #+#    #+#             */
/*   Updated: 2019/09/18 21:46:40 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_iswhite(char c)
{
	return (c == '\t' || c == ' ' || c == '\n');
}

static int		ft_get_start(char const *s)
{
	int		index;

	index = 0;
	while (ft_iswhite(s[index]))
		index++;
	return (index);
}

static int		ft_get_end(const char *s)
{
	int		index;

	index = ft_strlen(s) - 1;
	while (ft_iswhite(s[index]))
		index--;
	return (index);
}

static int		ft_trim_len(const char *s)
{
	if (ft_get_end(s) - ft_get_start(s) > 0)
		return (ft_get_end(s) - ft_get_start(s));
	return (0);
}

char			*ft_strtrim(char const *s)
{
	int		index;
	int		len;
	int		start;
	char	*trim;

	if (s != 0)
	{
		index = 0;
		len = ft_trim_len(s);
		start = ft_get_start(s);
		trim = (char *)malloc(sizeof(char) * ft_trim_len(s) + 2);
		if (trim)
		{
			while (index < len + 1)
			{
				trim[index] = s[start];
				start++;
				index++;
			}
			trim[index] = '\0';
		}
		return (trim);
	}
	return (0);
}
