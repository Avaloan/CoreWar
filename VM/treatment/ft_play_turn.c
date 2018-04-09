/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_turn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 04:42:08 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/09 05:27:40 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_load_waiting(t_env *e, t_process *proc)
{
	if (e->arena[proc->pc] < 18 && e->arena[proc->pc] > 0)
	{
		proc->to_exec = 1;
		proc->waiting = g_op_tab[e->arena[proc->pc] - 1].nb_cycle - 1;
	}
	else
		proc->pc++;
	return (1);
}

int	ft_play_turn(t_env *e)
{
	t_process	*tmp;

	tmp = e->pc_list;
	while (tmp)
	{
//		printf("pl = %i, location = %i\n", tmp->from_pl, tmp->pc);
		if (tmp->waiting == 0)
		{
			if (tmp->to_exec == 1)
			{
//				printf("AKApl = %i, location = %i && r1 = %u\n", tmp->from_pl, tmp->pc, tmp->reg[0]);
				if (!ft_operations(e, tmp))
					return (0);
				tmp->to_exec = 0;
			}
			else if (ft_load_waiting(e, tmp) == 0)
				return (0);
		}
		else
			tmp->waiting--;
		tmp = tmp->next;
	}
	return (1);
}
