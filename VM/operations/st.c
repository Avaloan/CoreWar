/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 05:15:24 by snedir            #+#    #+#             */
/*   Updated: 2018/04/06 04:43:15 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../VM/includes/corewar_vm.h"

void	st(t_env *e, t_process *process, t_args_value args[3])
{
	unsigned int	parameter;

	if (args[1].type == 'r')
		process->reg[args[1].reg] = process->reg[args[0].reg];
	else if (args[1].type == 'i')
		//parameter = read_nb_bytes(e, 4, process, args[1].ind % IDX_MOD);
		write_4_bytes(e, process->reg[args[0].reg - 1], process, args[1].ind);
}
