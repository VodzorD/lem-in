/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:46:54 by wscallop          #+#    #+#             */
/*   Updated: 2019/09/24 16:28:00 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		check_res(unsigned long long res, int neg)
{
	if (res > 9223372036854775807UL)
	{
		if (neg == -1)
			res = 0;
		else
			res = -1;
	}
	return (res);
}

int				ft_atoi(char *str)
{
	int					f_sign;
	unsigned long long	num;

	num = 0;
	f_sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' ||
	*str == '\f' || *str == '\r' || *str == ' ')
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			f_sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		++str;
	}
	if (num == 0)
		return (0);
	num = check_res(num, f_sign);
	return (num * f_sign);
}
