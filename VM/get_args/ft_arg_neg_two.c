/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_neg_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 12:55:51 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/14 14:51:52 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

short	ft_arg_neg_two(unsigned short nb, int mod)
{
	short	res;

	res = 0;
	//printf("nb = %i\n", nb);
	if (nb < 32768)
		return (nb % mod);
	else
		res = (short)nb;
	printf("%hd\n", res);
	return ((res % mod));
}
