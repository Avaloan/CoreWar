/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_turn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 04:42:08 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/22 05:48:25 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.h"

int	ft_load_waiting(t_emv *e, t_process *proc)
{
	proc->to_exec = 1;
	if (arena[proc->pc] < 18 && arena[proc->pc] > 0)
		ft_look_how_much_waiting(e);
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
				if (ft_op(e))//Samy
					return (0);
			else if (ft_load_waiting(e, tmp) == 0)//read l'octet et voir le temps d'attente necessaire, si octet n'a pas de waiting time, garder a 0 et avancer le pc
				return (0);
		}
		else
			tmp->waiting--;
		tmp = tmp->next;
	}
	return (1);
}
