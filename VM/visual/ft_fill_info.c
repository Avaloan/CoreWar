/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 03:48:25 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/13 13:03:58 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

void	ft_fill_process(t_env *e)
{
	int			i;
	int			pos;
	t_process	*tmp;

	tmp = e->pc_list;
	i = 0;
	pos = 9;
	while (tmp)
	{
		wmove(e->vi->info, pos + i, 4);
		wprintw(e->vi->info, "PC[%i] = %i | Carry = %i | Ex = %i",
				i, tmp->pc, tmp->carry, tmp->to_exec);
		tmp = tmp->next;
		i++;
	}
}

void	ft_fill_players(t_env *e)
{
	int	line;
	int	i;

	i = 0;
	line = (e->vi->my - 1) / 2 - 5;
	while (i < e->nb_of_pl)
	{
		wmove(e->vi->info, line, 3);
		wprintw(e->vi->info, "Player%i", i + 1);
		wmove(e->vi->info, line + 2, 4);
		wprintw(e->vi->info, "-> ID : %.8x", e->players[i].id);
		wmove(e->vi->info, line + 3, 4);
		wprintw(e->vi->info, "-> NAME : %.20s", e->players[i].name);
		wmove(e->vi->info, line + 4, 4);
		wprintw(e->vi->info, "-> Comment : %.20s", e->players[i].comment);
		wmove(e->vi->info, line + 5, 4);
		wprintw(e->vi->info, "-> Last_live : %i", e->players[i].last_live);
		wmove(e->vi->info, line + 6, 4);
		wprintw(e->vi->info, "-> Live : %i", e->players[i].lives_periode);
		i++;
		line += 8;
	}
}

int		ft_fill_info(t_env *e)
{
	int	i;
	int	pos;

	i = 0;
	pos = 2;
	box(e->vi->info, 0, 0);
	wmove(e->vi->info, pos, 10);
	wprintw(e->vi->info, "COREWAR : IN");
	wmove(e->vi->info, pos + 1, 4);
	wprintw(e->vi->info, "Cycle_periode : %.5i", e->cycles_periode);
	wmove(e->vi->info, pos + 2, 4);
	wprintw(e->vi->info, "Cycle : %.5i", e->cycles);
	wmove(e->vi->info, pos + 3, 4);
	wprintw(e->vi->info, "Cycles_to_Die : %.4i", e->cycles_to_die);
	wmove(e->vi->info, pos + 4, 4);
	wprintw(e->vi->info, "Checks_Done : %.4i/%.4i", e->checks_done, MAX_CHECKS);
	wmove(e->vi->info, pos + 5, 4);
	wprintw(e->vi->info, "Lives_read : %.3i/%.3i", e->lives_periode, NBR_LIVE);
	wmove(e->vi->info, pos + 6, 4);
	wprintw(e->vi->info, "Nbr_of_Players : %i", e->nb_of_pl);
	ft_fill_players(e);
	ft_fill_process(e);
	wmove(e->vi->info, e->vi->my - 3, 4);
	wprintw(e->vi->info, "e->vi->speed + freq = %i", e->vi->speed + FREQ);
//	wmove(e->vi->info, e->vi->my - 2, 4);
//	wprintw(e->vi->info, "Press X to know using");
	return (1);
}
