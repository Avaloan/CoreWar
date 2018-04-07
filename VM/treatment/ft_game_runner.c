/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_runner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 01:34:47 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/07 06:52:29 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int		ft_free_process(t_env *e)
{
	t_process	*tmp;

	tmp = e->pc_list;
	if (e->pc_list->next)
	{
		e->pc_list = e->pc_list->next;
		free(tmp);
		return (1);
	}
	else
		return (0);
}

int		ft_maj(t_env *e, int i)
{
	if (i == 1)
	{
		e->cycles_to_die = e->cycles_to_die - CYCLE_DELTA;
		e->checks_done = 0;
	}
	else
		e->checks_done++;
	e->lives_periode = 0;
	e->cycles_periode = 0;
	return (1);
}

int		ft_up_periode(t_env *e)
{
	t_process	*tmp;
	t_process	*tmp_2;

	while (e->pc_list && e->pc_list->lives_during_periode == 0)
		if (ft_free_process(e) == 0)
			return (2);
	tmp = e->pc_list;
	while (tmp->next)
	{
		tmp_2 = tmp->next;
		if (tmp_2 && tmp_2->lives_during_periode == 0)
		{
			tmp->next = tmp_2->next;
			free(tmp_2);
		}
		tmp->lives_during_periode = 0;
		tmp = tmp->next;
	}
	if (e->lives_periode > NBR_LIVE || e->checks_done >= MAX_CHECKS)
		ft_maj(e, 1);
	else
		ft_maj(e, 2);
	return (1);
}

int		ft_game_runner(t_env *e)
{
	int	a;

	a = 0;
	if (e->visu == 1)
		if (ft_start_the_game_visu(e) == 0)
			return (0);
	while (e->pc_list)
	{
		while (e->pc_list && e->cycles_periode < e->cycles_to_die)
		{
			if (e->cycles == e->dump_on)
				return (ft_dump(e));
			if (ft_play_turn(e) == 0)
				return (0);
			e->cycles_periode++;
			e->cycles++;
			if (e->visu == 1)
				if (ft_maj_visu(e) == 0)
					return (0);
		}
		if (e->cycles_periode == e->cycles_to_die)
			if ((a = ft_up_periode(e)) == 0 || a == 2)
				return (a);
	}
	return (1);
}
