/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 03:57:39 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/24 05:55:31 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

void	ft_fresh(t_env *e)
{
	t_process	*tmp;
	int			i;

	i = 0;
	if (e->pc_list)
	{
		while (tmp->next)
		{
			tmp = e->pc_list;
			e->pc_list = tmp->next;
			free(tmp);
		}
		free(e->pc_list);
	}
	free(e->arena);
	while (i < e->nb_of_pl)
	{
		free(e>player[i]->name);
		free(e>player[i]->comment);
		i++;
	}
	free(e->players);
	free(e->winner_name);
	free(e);
}

void	ft_claim_winner(t_env *e)
{
	int	i;

	i = 0;
	while (i < e->nb_of_pl)
	{
		if (e->player[i]->last_live > e->winner_value)
		{
			e->winner_value = e->player[i]->last_live;
			if ((e->winner_name = ft_strdup(e->player[i]->name)) == 0)
				return (0);;
		}	
		i++;
	}
	ft_printf("The Winner is \"%s\"\n", e->winner);
	return (1);
}

int		ft_finish(t_env *e)
{
	if (ft_claim_winner(e) == 0)
		return (0);
	ft_fresh(e);
	return (1);
}
