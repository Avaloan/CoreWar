/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 03:48:25 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/22 06:59:44 by gquerre          ###   ########.fr       */
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
	pos = 11;
	while (tmp)
	{
		if (i <= 6)
		{
			wmove(e->vi->info, pos + (i * 2), 4);
			wprintw(e->vi->info, "PC[%i] = %i | Carry = %i | Ex = %i",
				i, tmp->pc, tmp->carry, tmp->to_exec);
			wmove(e->vi->info, pos + (i * 2) + 1, 4);
			wprintw(e->vi->info, "Live_during_p = %.5d and Death = %.5d", tmp->lives_during_periode, (tmp->lives_during_periode) ? 0 : e->cycles_to_die - e->cycles_periode);
		}
		if (i > 6)
		{
			wmove(e->vi->info, pos + 14, 4);
			wprintw(e->vi->info, "%i PC More...", i - 6);
		}
		tmp = tmp->next;
		i += 1;
	}
	wmove(e->vi->info, pos - 2, 4);
	wprintw(e->vi->info, "Nbrs of process = [%.5i]", i);
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
		wprintw(e->vi->info, "Player_%i", i + 1);
		wmove(e->vi->info, line + 2, 4);
		wprintw(e->vi->info, "-> ID : %.8x", e->players[i].id);
		wmove(e->vi->info, line + 3, 4);
		wprintw(e->vi->info, "-> NAME : %.16s", e->players[i].name);
		wmove(e->vi->info, line + 4, 4);
//		wprintw(e->vi->info, "-> Comment : %.16s", e->players[i].comment);
//		wmove(e->vi->info, line + 5, 4);
		wprintw(e->vi->info, "-> Last_live : %.6i", e->players[i].last_live);
		wmove(e->vi->info, line + 5, 4);
		wprintw(e->vi->info, "-> Live : %.6i", e->players[i].lives_periode);
		i++;
		line += 8;
	}
}

int		ft_fill_info(t_env *e)
{
	int	i;
	int	pos;

	i = 0;
	pos = 1;
	box(e->vi->info, 0, 0);
	wmove(e->vi->info, pos, 10);
	wprintw(e->vi->info, "COREWAR : *IN PROGRESS*");
	wmove(e->vi->info, pos + 2, 4);
	wprintw(e->vi->info, "Cycle_periode : %.5i", e->cycles_periode);
	wmove(e->vi->info, pos + 3, 4);
	wprintw(e->vi->info, "Cycle : %.5i", e->cycles);
	wmove(e->vi->info, pos + 4, 4);
	wprintw(e->vi->info, "Cycles_to_Die : %.4i", e->cycles_to_die);
	wmove(e->vi->info, pos + 5, 4);
	wprintw(e->vi->info, "Checks_Done : %.4i/%.4i", e->checks_done, MAX_CHECKS);
	wmove(e->vi->info, pos + 6, 4);
	wprintw(e->vi->info, "Lives_read : %.3i/%.3i", e->lives_periode, NBR_LIVE);
	wmove(e->vi->info, pos + 7, 4);
	wprintw(e->vi->info, "Nbr_of_Players : %i", e->nb_of_pl);
	ft_fill_players(e);
	ft_fill_process(e);
	wmove(e->vi->info, e->vi->my - 3, 4);
	wprintw(e->vi->info, "VITESSE = %.2i", 10 - ((e->vi->speed + FREQ) / 100000));
	wmove(e->vi->info, e->vi->my + 2, 0);
//	wmove(e->vi->info, e->vi->my - 2, 4);
//	wprintw(e->vi->info, "Press X to know using");
	return (1);
}
