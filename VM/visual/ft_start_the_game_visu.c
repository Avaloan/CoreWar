/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_the_game_visu.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 06:16:10 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/27 06:42:53 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_start_info(t_env *e)
{
	wmove(info, CYCLE_POS, e->vi->mx + 4);
	wmove(info, CYCLE_TO_DIE_POS, e->vi->mx + 4);
	wmove(info, PLACE_OF_P1, e->vi->mx + 4);
	wmove(info, PLACE_OF_P2, e->vi->mx + 4);
	...
}
int	ft_start_visu_arena(t_env *e)
{
	int	i;
	int	j;
	int cmp;

	cmp = 0;
	i = 1;
	j = 1;
	while (j < e->vi->my && cmp < 4096)
	{
		while (i < e->vi->mx && cmp < 4096)
		{
			wmove(arena, j, i);
			wprintw(arena, " ");
			wprintw(arena, "%.2hc", e->arena[cmp]);
			i += 3;
			cmp++;
		}
		j++;
		i = 1;
	}
}

int	ft_start_the_game_visu(t_env *e)
{
	if (ft_start_visu_arena(e) == 0)
		return (0);
	if (ft_strart_visu_info(e))
		return (0);
	wrefresh(arena);
	wrefresh(info);
	getch();
	return (1);
}
