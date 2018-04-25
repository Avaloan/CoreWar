/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 05:21:24 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/25 01:59:22 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

void	ft_print_inf(t_env *e)
{
	t_process	*tmp;
	int			i;

	tmp = e->pc_list;
	i = 0;
	while (tmp)
	{
		printf("process[%d] : pos = %d || value = [%d]\n", i, tmp->pc, e->arena[tmp->pc]);
		i++;
		tmp = tmp->next;
	}
	printf("nbrs_of_Process = [%d]\n", i);
}

int	ft_dump(t_env *e)
{
	int	i;
	int	v;
	
	i = 0;
	ft_print_inf(e);
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
