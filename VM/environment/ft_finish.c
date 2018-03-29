/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 03:57:39 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/29 05:31:12 by gquerre          ###   ########.fr       */
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
		free(e->players[i].name);
		free(e->players[i].comment);
		i++;
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
			printf("i = %i\n", i);
			printf("str = %s\n", e->players[i].name);
			e->winner_value = e->players[i].last_live;
			if ((e->winner_name = ft_strdup(e->players[i].name)) == 0)
				return (0);
		}	
		i++;
	}
	printf("The Winner is \"%s\"\n", e->winner_name);
	return (1);
}

int		ft_finish(t_env *e)
{
	if (ft_claim_winner(e) == 0)
		return (0);
	if (e->visu == 1)
		ft_end_visu(e);
	ft_fresh(e);
	return (1);
}
