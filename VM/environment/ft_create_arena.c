/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_arena.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 02:07:51 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/29 05:24:40 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_create_arena(t_env *e)
{
	if (!(e->arena = (ft_memalloc(sizeof(unsigned char) * (MEM_SIZE)))))
		return (0);
	if (!(e->pc_list = ft_memalloc(sizeof(t_process *))))
		return (0);
	e->cycles_to_die = CYCLE_TO_DIE;
	e->cycles = 0;
	e->cycles_periode = 0;
	e->checks_done = 0;
	e->lives_periode = 0;
	e->option = 0;
	e->winner_value = 0;
	e->winner_name = NULL;
	return (1);
}
