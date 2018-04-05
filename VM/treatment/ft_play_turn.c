/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_turn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 04:42:08 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/31 08:38:13 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_load_waiting(t_env *e, t_process *proc)
{
	if (e->arena[proc->pc] == 9 && proc->carry == 0)
		proc->pc++;
	else if (e->arena[proc->pc] < 18 && e->arena[proc->pc] > 0)
		// Verifie si la case est un OP code valable et si on doit chercher un temps d attente
	{
		proc->to_exec = 1;
	//	proc->waiting = g_op_tab[e->arena[proc->pc]].nb_cycles;//Vrai ligne => integrer g_op_tab pour fonctionner
		proc->waiting = 10;// juste pour tester le visu
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
		if (tmp->waiting == 0)
		{
			if (tmp->to_exec == 1)
			{
			//	if (!ft_operations(e))//Samy
			//		return (0);
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
