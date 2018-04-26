/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 05:21:24 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/26 01:42:11 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_dump(t_env *e)
{
	int	i;
	int	v;

	i = 0;
	while (i < MEM_SIZE)
	{
		v = 0;
		while (i < MEM_SIZE && v < 32)
		{
			ft_print_hexa(e->arena[i]);
			if (v != 31)
				ft_putchar(' ');
			v++;
			i++;
		}
		ft_putchar('\n');
	}
	return (1);
}
