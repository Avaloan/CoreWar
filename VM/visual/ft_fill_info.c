/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 03:48:25 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/07 03:42:15 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

void	ft_fill_players(t_env *e)
{
	int	line;
	int	i;

	i = 0;
	line = (e->vi->my - 1) / 2;
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
		wprintw(e->vi->info, "-> Live : %i", e->pc_list->lives_during_periode);
		i++;
		line += 7;
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
	pos += 2;
	wmove(e->vi->info, pos, 4);
	wprintw(e->vi->info, "Cycle : %i", e->cycles);
	pos += 1;
	wmove(e->vi->info, pos, 4);
	wprintw(e->vi->info, "Cycles_to_Die : %i", e->cycles_to_die);
	pos += 1;
	wmove(e->vi->info, pos, 4);
	wprintw(e->vi->info, "Checks_Done : %i/%i", e->checks_done, MAX_CHECKS);
	pos += 1;
	wmove(e->vi->info, pos, 4);
	wprintw(e->vi->info, "Nbr_of_Players : %i", e->nb_of_pl);
	ft_fill_players(e);
	wmove(e->vi->info, e->vi->my - 2, 4);
	wprintw(e->vi->info, "Press X to know using");
	return (1);
}
