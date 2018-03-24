/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_pc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 05:48:31 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/24 05:56:16 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_add_pc(t_env *e, t_process *father, int i)
{
	t_process	*tmp;
	t_process	*tmp2;
	int			k;

	k = 0;
	tmp2 = NULL;
	if (!(tmp = ft_memalloc(sizeof(t_process*))))
		return (0);
	tmp->pc = father->pc + (int)(e->arena[father->pc + i]);
	tmp->waiting = father->waiting;
	tmp->live_during_periode = father->live_during_periode;
	tmp->carry = father->carry;
	while (k < REG_NUMBER)
	{
		tmp->reg[k] = father->reg[k];
		k++;
	}
	tmp2 = father->next;
	tmp->next = tmp2;
	father->next = tmp;
	return (1);
}
