/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 05:15:24 by snedir            #+#    #+#             */
/*   Updated: 2018/04/15 23:42:49 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../VM/includes/corewar_vm.h"

void	sti(t_env *e, t_process *process, t_args_value args[3])
{
	unsigned int parameter;

	printf("r1 = %x, r2 = %x, r3 = %x, r4 = %x\n", process->reg[0], process->reg[1], process->reg[2], process->reg[3]);
	parameter = 0;
	if (args[1].type == 'r')
		parameter += process->reg[args[1].reg - 1];
	else if (args[1].type == 'i')
		parameter += read_nb_bytes(e, 4, process, args[1].ind
				/*ft_arg_neg_two(args[1].ind, IDX_MOD)*/);
	else if (args[1].type == 'd')
		parameter += args[1].dir_short;
	printf("parameters1 = %i\n", parameter);
	if (args[2].type == 'd')
		parameter += args[2].dir_short;
	else if (args[2].type == 'r')
		parameter += ft_arg_neg_three(process->reg[args[2].reg - 1], IDX_MOD);
	printf("parameters = %i\n", parameter);
	write_4_bytes(e, process->reg[args[0].reg - 1], process,
			ft_arg_neg_two(parameter, IDX_MOD));
}
