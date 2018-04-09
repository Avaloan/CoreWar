/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 06:15:30 by snedir            #+#    #+#             */
/*   Updated: 2018/04/09 05:15:37 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../VM/includes/corewar_vm.h"

void	lldi(t_env *e, t_process *process, t_args_value args[3])
{
	unsigned int parameter;

	parameter = 0;
	if (args[0].type == 'r')
		parameter += process->reg[args[0].reg - 1];
	else if (args[0].type == 'd')
		parameter += args[0].dir;
	else if (args[0].type == 'i')
		parameter += read_nb_bytes(e, 4, process, args[0].ind % MEM_SIZE);
	if (args[1].type == 'd')
		parameter += args[1].dir;
	if (args[1].type == 'r')
		parameter += process->reg[args[1].reg - 1];
	process->reg[args[2].reg - 1] =
		read_nb_bytes(e, 4, process, parameter % MEM_SIZE);
	if (parameter == 0)
		process->carry = 1;
}
