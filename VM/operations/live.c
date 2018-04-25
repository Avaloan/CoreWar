/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 06:14:13 by snedir            #+#    #+#             */
/*   Updated: 2018/04/25 04:46:32 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../VM/includes/corewar_vm.h"

void	live(t_env *e, t_process *process, t_args_value args[3])
{
	unsigned int	parameter;
	int				i;

	i = -1;
	parameter = args[0].dir;
	while (++i < e->nb_of_pl)
	{
		if (e->players[i].id == parameter)
		{
			e->players[i].lives_periode++;
			e->players[i].total_lives++;
			e->players[i].last_live = e->cycles;
			break ;
		}
	}
	process->lives_during_periode++;
	e->lives_periode++;
}
