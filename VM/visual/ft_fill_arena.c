/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_arena.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 03:41:03 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/29 07:37:32 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_fill_arena(t_env *e)
{
	int	i;
	int	j;
	int cmp;
	static int	cheat = 0;

	cmp = 0;
	i = 1;
	j = 1;
	box(e->vi->arena, 0, 0);
	while (j < e->vi->my - 2 && cmp < MEM_SIZE)
	{
		while (i < e->vi->mx - 2 && cmp < MEM_SIZE)
		{
			wmove(e->vi->arena, j, i);
			wprintw(e->vi->arena, " ");
			wprintw(e->vi->arena, "%.2x", e->arena[cmp]);
			i += 3;
			cmp++;
		}
		j++;
		i = 1;
	}
	cheat++;
	return (1);
}
