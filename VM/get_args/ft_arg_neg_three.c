/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_neg_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 12:55:51 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/15 19:53:25 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_arg_neg_three(unsigned int nb, int mod)
{
	int	res;

	res = 0;
	if (nb < 2147483648)
		return (nb % mod);
	else
		res = (int)nb;
	return ((res % mod));
}
