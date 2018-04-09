/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 06:13:03 by snedir            #+#    #+#             */
/*   Updated: 2018/04/09 05:12:00 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../VM/includes/corewar_vm.h"

void	c_fork(t_env *e, t_process *process, t_args_value args[3])
{
	ft_add_pc(e, process, args[0].dir % IDX_MOD);
}
