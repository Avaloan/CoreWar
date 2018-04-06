/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 06:15:00 by snedir            #+#    #+#             */
/*   Updated: 2018/04/06 04:54:27 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../VM/includes/corewar_vm.h"

void	zjmp(t_env *e, t_process *process, t_args_value args[3])
{
	if (process->carry == 1)
		process->pc += args[0].dir % IDX_MOD;
}
