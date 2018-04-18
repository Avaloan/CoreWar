/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 05:15:24 by snedir            #+#    #+#             */
/*   Updated: 2018/04/18 13:15:25 by gquerre          ###   ########.fr       */
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
		parameter += read_nb_bytes(e, 4, process, /*args[1].ind*/
				ft_arg_neg_two(args[1].ind, IDX_MOD));
	else if (args[1].type == 'd')
		parameter += ft_arg_neg_two(args[1].dir_short, IDX_MOD);
	if (args[2].type == 'd')
		parameter += ft_arg_neg_two(args[2].dir_short, IDX_MOD);
	else if (args[2].type == 'r')
		parameter += ft_arg_neg_three(process->reg[args[2].reg - 1], IDX_MOD);
	write_4_bytes(e, process->reg[args[0].reg - 1], process,
			ft_arg_neg_two(parameter, IDX_MOD));
}
