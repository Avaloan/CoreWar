/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_pc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 05:48:31 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/13 15:08:53 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_add_pc(t_env *e, t_process *father, int i)
{
	t_process	*tmp;
	int			k;

	k = 0;
	tmp = NULL;
	if (!(tmp = ft_memalloc(sizeof(t_process))))
		return (0);
//	tmp->pc = father->pc + (int)(e->arena[father->pc + i]);
	tmp->pc = father->pc + (int)i;
	tmp->waiting = father->waiting;
	tmp->lives_during_periode = father->lives_during_periode;
	tmp->carry = father->carry;
	tmp->from_pl = father->from_pl;
	while (k < REG_NUMBER)
	{
		tmp->reg[k] = father->reg[k];
		k++;
	}
	tmp->next = father->next;
	father->next = tmp;
	return (1);
}
