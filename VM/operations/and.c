/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 06:11:44 by snedir            #+#    #+#             */
/*   Updated: 2018/04/06 06:17:32 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../VM/includes/corewar_vm.h"

void	_and(t_env *e, t_process *process, t_args_value args[3])
{
	unsigned int first;
	unsigned int second;

	first = 0;
	second = 0;
	if (args[0].type == 'r')
		first = process->reg[args[0].reg - 1];
	else if (args[0].type == 'd')
		first = args[0].dir;
	else if (args[0].type == 'i')
		first = read_nb_bytes(e, 4, process, args[0].ind % IDX_MOD);
	if (args[1].type == 'r')
		second = process->reg[args[1].reg - 1];
	else if (args[1].type == 'd')
		second = args[1].dir;
	else if (args[1].type == 'i')
		second = read_nb_bytes(e, 4, process, args[1].ind % IDX_MOD);
	process->reg[args[2].reg] = first & second;
}
