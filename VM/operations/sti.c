/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 05:15:24 by snedir            #+#    #+#             */
/*   Updated: 2018/04/07 00:59:18 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../VM/includes/corewar_vm.h"

void	sti(t_env *e, t_process *process, t_args_value args[3])
{
	unsigned int parameter;

	parameter = 0;
	if (args[1].type == 'r')
		parameter += process->reg[args[1].reg - 1];
	else if (args[1].type == 'i')
		parameter += read_nb_bytes(e, 4, process, args[1].ind % IDX_MOD);
	else if (args[1].type == 'd')
		parameter += args[1].dir;
	if (args[2].type == 'd')
		parameter += args[2].dir;
	else if (args[2].type == 'r')
		parameter += process->reg[args[1].reg - 1];
	write_4_bytes(e, process->reg[args[0].reg - 1], process, parameter %
			IDX_MOD);
}
