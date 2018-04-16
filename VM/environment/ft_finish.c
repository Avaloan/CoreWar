/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 03:57:39 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/16 15:05:27 by gquerre          ###   ########.fr       */
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
		while (tmp && tmp->next)
		{
			tmp = e->pc_list;
			e->pc_list = tmp->next;
			free(tmp);
		}
		free(e->pc_list);
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

int		ft_claim_winner(t_env *e)
{
	int	i;

	i = 0;
	while (i < e->nb_of_pl)
	{
		if (e->players[i].last_live >= e->winner_value)
		{
			e->winner_value = e->players[i].last_live;
			if ((e->winner_name = ft_strdup(e->players[i].name)) == 0)
				return (0);
		}
		i++;
	}
	ft_putstr("The Winner is");
	ft_putchar('"');
	ft_putstr(e->winner_name);
	ft_putchar('"');
	return (1);
}

int		ft_finish(t_env *e)
{
	if (e->visu == 1)
		ft_end_visu(e);
	if (ft_claim_winner(e) == 0)
		return (0);
	ft_fresh(e);
	return (1);
}
