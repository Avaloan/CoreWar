/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 05:15:24 by snedir            #+#    #+#             */
/*   Updated: 2018/04/05 01:07:18 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include <math.h>
#include <stdlib.h>

void	ld(t_env *e, t_process *process, t_args_value args[3])
{
	unsigned int	parameter;

	if (args[0].type == 'd')
		parameter = args[0].dir;
	else
		parameter = read_nb_bytes(e, 2, process, args[0].ind % IDX_MOD);
	process->reg[args[1].reg] = parameter;
}
