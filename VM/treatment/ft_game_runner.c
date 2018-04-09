/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_runner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 01:34:47 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/09 06:20:41 by gquerre          ###   ########.fr       */
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
	t_process	*tmp;

	if (!(e->pc_list))
			return (0);
	tmp = e->pc_list;
	if (i == 1)
	{
		e->cycles_to_die = e->cycles_to_die - CYCLE_DELTA;
		e->checks_done = 0;
	}
	else
		e->checks_done++;
	e->lives_periode = 0;
	e->cycles_periode = 0;
	while (tmp)
	{
		tmp->lives_during_periode = 0;
		tmp = tmp->next;
	}
	return (1);
}

int		ft_up_periode(t_env *e)
{
	t_process	*tmp;
	t_process	*tmp_2;

//	printf("NB DE LIFE = %i\n", e->pc_list->lives_during_periode);
	while (e->pc_list && e->pc_list->lives_during_periode == 0)
		if (ft_free_process(e) == 0)
			return (2);
	tmp = e->pc_list;
//	printf("NB DE LIFE = %iUUUU\n", e->pc_list->lives_during_periode);
	while (tmp && tmp->next)
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
//	printf("NB DE LIFE = YOLO%i\n", e->pc_list->lives_during_periode);
	if (e->lives_periode > NBR_LIVE || e->checks_done >= MAX_CHECKS)
		ft_maj(e, 1);
	else
		ft_maj(e, 2);
//	printf("NB DE LIFE = %i + 5\n", e->pc_list->lives_during_periode);
	return (1);
}

int		ft_game_runner(t_env *e)
{
	int	a;

//	SDL_Init(SDL_INIT_EVERYTHING);
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
			{
//				SDL_Quit();
				return (0);
			}
			if (e->visu == 1)
				if (ft_maj_visu(e) == 0)
				{
//					SDL_Quit();
					return (0);
				}
			e->cycles_periode++;
			e->cycles++;
			sleep(1);
			timeout(FREQ + e->vi->speed);
//			SDL_Delay(500);
		}
//		SDL_Quit();
		if (e->cycles_periode == e->cycles_to_die)
			if ((a = ft_up_periode(e)) == 0 || a == 2)
			{
//				SDL_Quit();
				return (a);
			}
	}
//	SDL_Quit();
	return (1);
}
