/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 03:57:39 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/26 02:30:46 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

void	ft_fresh(t_env *e)
{
	t_process	*tmp;
	int			i;

	i = -1;
	if (e->pc_list)
	{
		tmp = e->pc_list;
		while (tmp->next)
		{
			tmp = e->pc_list;
			e->pc_list = tmp->next;
			free(tmp);
		}
	}
	free(e->arena);
	free(e->written_by);
	while (++i < e->nb_of_pl)
	{
		free(e->players[i].name);
		free(e->players[i].comment);
	}
	free(e->players);
	free(e->winner_name);
	free(e);
}

int		ft_fight_under_the_moon(t_env *e, int i)
{
	
	if ((e->players[i].last_live > e->winner_value) ||
			((e->players[i].last_live == e->winner_value) &&
			(e->players[i].very_last_flag > e->winner_flag)))
	{
		printf("e->pl = %u, e->pl_last_live = %u, e->pl_flag = %u\n", i, e->players[i].last_live, e->players[i].very_last_flag);
		e->winner_value = e->players[i].last_live;
		e->winner_flag = e->players[i].very_last_flag;
		if ((e->winner_name = ft_strdup(e->players[i].name)) == 0)
			return (0);
			e->winner_num_player = e->players[i].num_player;
	}
	return (1);
}

int		ft_claim_winner(t_env *e)
{
	int	i;

	i = 0;
	while (i < e->nb_of_pl)
	{
		if (ft_fight_under_the_moon(e, i) == 0)
			return (0);
		/*if (e->players[i].last_live >= e->winner_value)
		{

			e->winner_value = e->players[i].last_live;
			if ((e->winner_name = ft_strdup(e->players[i].name)) == 0)
				return (0);
			e->winner_num_player = e->players[i].num_player;
		}*/
		i++;
	}
	ft_putstr("The Winner is ");
	ft_putchar('"');
	ft_putstr(e->winner_name);
	ft_putchar('"');
	ft_putstr(" Player ");
	ft_putnbr(e->winner_num_player);
	return (1);
}

int		ft_finish(t_env *e)
{
	getch();
	if (e->visu == 1)
		ft_end_visu(e);
	if (ft_claim_winner(e) == 0)
		return (0);
	ft_fresh(e);
	return (1);
}
