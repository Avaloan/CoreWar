/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 05:15:24 by snedir            #+#    #+#             */
/*   Updated: 2018/04/06 03:21:48 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../VM/includes/corewar_vm.h"

void	st(t_env *e, t_process *process, t_args_value args[3], int offset)
{
	unsigned int	parameter;

	if (args[1].type == 'r')
	{
		printf("args[0].reg %d\n", args[0].reg);
		process->reg[args[1].reg] = process->reg[args[0].reg];
	}
	else if (args[1].type == 'i')
	{
		printf("rly ?\n");
		//parameter = read_nb_bytes(e, 4, process, args[1].ind % IDX_MOD);
		printf("numero reg %d || Value reg %d\n", args[0].reg,
				process->reg[args[0].reg]);
		write_4_bytes(e, process->reg[args[0].reg - 1], 4, process, args[1].ind);
	}
}
