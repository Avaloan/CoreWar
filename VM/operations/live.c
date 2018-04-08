/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 06:14:13 by snedir            #+#    #+#             */
/*   Updated: 2018/04/07 05:44:36 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../VM/includes/corewar_vm.h"

void	live(t_env *e, t_process *process, t_args_value args[3])
{
	unsigned int parameter;
	int i;
	int done;

	i = -1;
	done = 1;
	parameter = (unsigned int)args[0].dir;

	//printf("param %u && id = e->players[i].id = %u && pc %d\n", parameter, e->players[0].id, e->pc_list->pc);
	while (++i < e->nb_of_pl)
		if (e->players[i].id == parameter)
		{
			e->players[i].lives_periode++;
			e->players[i].total_lives++;
			e->players[i].last_live = e->cycles;
			done = 1;
			process->lives_during_periode++;
			break;
		}
	if (done != 1)
		e->lives_periode++;
}
