/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 02:07:51 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/25 04:33:36 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

void			write_4_bytes(t_env *e, int input, t_process *pc, unsigned int off)
{
	unsigned int	i;
	unsigned int	tmp;
	int				targ;

	targ = 0;
	i = 0;
	tmp = 0;
//	printf("input = %i\n", input);
	while (i < INT_SIZE)
	{
		targ = pc->pc + off + i;
		targ = (targ < 0) ? MEM_SIZE + targ : targ;
		tmp = input >> 8 * (INT_SIZE - 1);
//	printf("pos_write = %i\n",  pc->pc + off + i - 1);
//	printf("pos_write_targ = %i\n", targ);
		e->arena[targ % MEM_SIZE] = tmp;
		e->written_by[targ % MEM_SIZE] = pc->from_pl;
		i++;
		input = input << 8;
	}
}
