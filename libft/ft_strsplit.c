/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:09:52 by wscallop          #+#    #+#             */
/*   Updated: 2020/11/24 18:46:08 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		get_count(char const *str, char c)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

static int		get_word_len(char const *str, char c)
{
	int i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

int				ft_free_tab(void ***arr)
{
	void	**temp;

	if (!(*arr))
		return (1);
	temp = *arr;
	while (**arr)
	{
		ft_memdel(*arr);
		(*arr)++;
	}
	free(temp);
	temp = NULL;
	*arr = temp;
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**s2;

	if (s && (s2 = (char **)malloc(sizeof(char *) * (get_count(s, c) + 1))))
	{
		i = -1;
		j = 0;
		while (++i < get_count(s, c))
		{
			k = 0;
			if (!(s2[i] = ft_strnew(get_word_len(&s[j], c) + 1)))
				return (ft_free_tab((void ***)&s2) ? NULL : NULL);
			while (s[j] == c)
				j++;
			while (s[j] != c && s[j])
				s2[i][k++] = s[j++];
			s2[i][k] = '\0';
		}
		s2[i] = 0;
		return (s2);
	}
	return (NULL);
}
