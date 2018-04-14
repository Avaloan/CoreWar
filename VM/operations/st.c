/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 05:15:24 by snedir            #+#    #+#             */
/*   Updated: 2018/04/14 15:38:01 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../VM/includes/corewar_vm.h"

void	st(t_env *e, t_process *process, t_args_value args[3])
{
	if (args[1].type == 'r')
	{
		printf("UUU");
		process->reg[args[1].reg - 1] = process->reg[args[0].reg - 1];
	}
	else if (args[1].type == 'i')
	{
		printf("OOOOUUU");
		write_4_bytes(e, process->reg[args[0].reg - 1], process,
				ft_arg_neg_two(args[1].ind, IDX_MOD));
	}
}
