/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 06:15:00 by snedir            #+#    #+#             */
/*   Updated: 2018/04/16 13:51:08 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../VM/includes/corewar_vm.h"

void	zjmp(t_env *e, t_process *process, t_args_value args[3])
{
	if (process->carry == 1)
	{
		process->pc += ft_arg_neg_two(args[0].dir_short, IDX_MOD);
		process->pc = (process->pc < 0) ? MEM_SIZE + process->pc : process->pc;
	}
	else
		process->pc += 3;
	
	/*	printf("%i\n", process->pc);
	printf("%hu\n", args[0].dir_short);
	printf("%hi\n", ft_arg_neg_two(args[0].dir_short, IDX_MOD));
	exit(0);*/
}
