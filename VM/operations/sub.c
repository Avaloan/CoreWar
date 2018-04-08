/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 06:14:31 by snedir            #+#    #+#             */
/*   Updated: 2018/04/06 04:47:47 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../VM/includes/corewar_vm.h"

void	sub(t_env *e, t_process *process, t_args_value args[3])
{
	process->reg[args[2].reg - 1] = process->reg[args[0].reg - 1] -
		process->reg[args[1].reg - 1];
	if (process->reg[args[2].reg] == 0)
		process->carry = 1;
}
