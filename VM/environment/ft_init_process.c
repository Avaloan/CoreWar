/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 01:02:45 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/06 05:23:23 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

void	ft_save_first(t_env *e, t_process *first)
{
	int	k;

	k = 0;
	first->pc = 0;
	first->reg[k] = e->players[0].id;
	first->waiting = 0;
	first->lives_during_periode = 0;
	first->carry = 0;
	first->to_exec = 0;
	first->from_pl = 1;
	while (++k < REG_NUMBER)
		first->reg[k] = 0;
	first->next = NULL;
}

int		ft_init_process(t_env *e)
{
	t_process	*tmp;
	int			i;
	int			k;

	i = 0;
	k = 0;
	tmp = e->pc_list;
	ft_save_first(e, tmp);
	while (++i < e->nb_of_pl)
	{
		if (!(tmp->next = ft_memalloc(sizeof(t_process))))
			return (0);
		tmp->next->pc = i * MEM_SIZE / e->nb_of_pl;
		tmp->next->reg[k] = e->players[i].id;
		tmp->next->waiting = 0;
		tmp->next->lives_during_periode = 0;
		tmp->next->carry = 0;
		tmp->next->to_exec = 0;
		tmp->next->from_pl = i + 1;
		while (++k < REG_NUMBER)
			tmp->next->reg[k] = 0;
		tmp->next->next = NULL;
		tmp = tmp->next;
	}
	return (1);
}
