/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_runner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 01:34:47 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/22 05:36:53 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.h"

int	ft_free_process(t_env *e, int flag)
{
	if (flag == 1)
	{

	}
	else
	{

	}
}

int	ft_maj(t_env *e, int i)
{
	if (i == 1)
	{
		e->cycle_to_die = e->cycle_to_die - CYCLE_DETA;
		e->checks_done = 0;
	}
	else
		e->checks_done++;
	e->lives_periode = 0;
	e->cycles_periode = 0;
	return (1);
}
int	ft_up_periode(t_env *e)
{
	t_process	*tmp;
	t_process	*tmp_2;

	while (e->pc_List && e->pc_list->lives_during_periode == 0)
		ft_free_process(e, NULL, 1);//free le process et "e->pc_list = e->pc_list->next avant
	tmp = e->pc_list;
	while (tmp->next)
	{
		tmp_2 = tmp->next;
		if (tmp_2 && tmp_2->lives_during_periode == 0)
		{
			tmp->next = tmp_2->next;
			ft_free_process(e, tmp_2, 2);//free le process
		}
		tmp->lives_during_periode = 0;
		tmp = tmp->next;
	}
	if (e->lives_periode > NBR_LIVE || e->checks_done >= MAX_CHECKS)
		if (ft_maj(e, 1) == 0)
			return (0);
	else if (ft_maj(e, 2) == 0)
		return (0);
	return (1);
}

int	ft_game_runner(t_env *e)
{
	while (e->pc_List)
	{
		while (e->pc_list && e->cycles < e->cycles_to_die)
		{
			if (ft_play_turn(e) == 0)
				return (0);
			e->cycles_periode++;
			e->cycles++;
		}
		if (e->cycles->periode == e->cycles_to_die)
			if (ft_up_periode(e) == 0)
				return (0);
	}
	return (1);
}
