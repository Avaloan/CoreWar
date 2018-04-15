/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 06:15:06 by snedir            #+#    #+#             */
/*   Updated: 2018/04/15 23:18:48 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../VM/includes/corewar_vm.h"

void	ldi(t_env *e, t_process *process, t_args_value args[3])
{
	unsigned int parameter;

	parameter = 0;
//	printf("arg[0].type = %c, arg[1].type = %c\, arg[0].dir_short = %hu"
	if (args[0].type == 'r')
		parameter += process->reg[args[0].reg - 1];
	else if (args[0].type == 'd')
		parameter += ft_arg_neg_two(args[0].dir_short, IDX_MOD) - 2;
	else if (args[0].type == 'i')
		parameter += read_nb_bytes(e, 4, process,
				ft_arg_neg_two(args[0].ind, IDX_MOD));
	if (args[1].type == 'd')
		parameter += args[1].dir_short;
	else if (args[1].type == 'r')
		parameter += process->reg[args[1].reg - 1];
	process->reg[args[2].reg - 1] =
		read_nb_bytes(e, 4, process, ft_arg_neg_three(parameter, IDX_MOD));
}
