/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:47:29 by wscallop          #+#    #+#             */
/*   Updated: 2019/09/18 21:46:40 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	size_t	index;

	index = 10000000000;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n == 0)
		ft_putstr_fd("0", fd);
	else
	{
		if (n < 0 && (n *= -1))
			ft_putchar_fd('-', fd);
		while (n / index == 0)
			index /= 10;
		while (index != 0)
		{
			if (n / index == 0)
				ft_putchar_fd('0', fd);
			else
				ft_putchar_fd(n / index + 48, fd);
			n = n % index;
			index /= 10;
		}
	}
}
