/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrposition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:12:39 by wscallop          #+#    #+#             */
/*   Updated: 2020/11/24 18:46:38 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_char_position(const char *str, char c)
{
	int	position;

	if (str)
	{
		position = 0;
		while (str[position] != '\0')
		{
			if (str[position] == c)
				return (position);
			position++;
		}
		return (-1);
	}
	return (-1);
}
