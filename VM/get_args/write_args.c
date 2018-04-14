/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 02:07:51 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/14 15:39:57 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

void			write_4_bytes(t_env *e, int input, t_process *pc, unsigned int off)
{
	unsigned int	i;
	unsigned int	tmp;

	i = 0;
	tmp = 0;
	printf("input = %i\n", input);
	while (i < INT_SIZE)
	{
		tmp = input >> 8 * (INT_SIZE - 1);
	printf("pos_write = %i\n",  pc->pc + off + i - 1);
		e->arena[pc->pc + off + i - 1] = tmp;
		e->written_by[pc->pc + off + i - 1] = pc->from_pl;
		i++;
		input = input << 8;
	}
}

void			write_2_bytes(t_env *e, unsigned short input, t_process *pc, unsigned int off)
{
	unsigned int	i;
	unsigned short	tmp;

	i = 0;
	tmp = 0;
	while (i < INT_SIZE - 2)
	{
		tmp = input >> 8;
		e->arena[pc->pc + off + i - 1] = tmp;
		e->written_by[pc->pc + off + i - 1] = pc->from_pl;
		i++;
		input = input << 8;
	}
}
