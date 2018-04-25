/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:09:33 by fdidelot          #+#    #+#             */
/*   Updated: 2018/04/25 04:36:38 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	res;
	int					sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\r' || *str == '\f')
		str++;
	sign = (*str == '-' ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	if (res > 9223372036854775807)
	{
		if (sign < 0)
			return (0x00000000);
		return (0xffffffff);
	}
	return (sign * res);
}
