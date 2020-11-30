/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:13:27 by wscallop          #+#    #+#             */
/*   Updated: 2019/09/24 21:33:38 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*head;

	if (s1 && s2)
	{
		new = (char *)malloc(sizeof(char) * (ft_strlen(s1)
		+ ft_strlen(s2) + 1));
		head = new;
		if (!new)
			return (NULL);
		while (*s1 != '\0')
			*new++ = *s1++;
		while (*s2 != '\0')
			*new++ = *s2++;
		*new = '\0';
		return (head);
	}
	return (NULL);
}
