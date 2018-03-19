/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 01:02:45 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/19 05:41:31 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_save_first(t_env *e, t_process *first)
{
	int	k;

	k = 0;
	first->pc = 0;
	first->reg[k] = e->player[1][ID];
	first->waiting = 0;
	first->live_during_periode = 0;
	first->carry = 0;
	while (++k < 16)
		first->reg[k] = 0;
	first->next = NULL;
}
int		ft_init_process(t_env *e)
{
	t_process	*tmp;
	int			i;
	int			k;

	i = 1;
	k = 0;
	tmp = e->pc_list;
	ft_save_first(e, tmp);
	while (i < e->nb_of_pl)
	{
		if (!(tmp->next = ft_memalloc(sizeof(t_process *))))
			return (0);
		tmp->next->pc = i * MEM_SIZE / e->nb_of_pl;
		tmp->next->reg[k] = e->player[i][ID];
		tmp->next->waiting = 0;
		tmp->next->live_during_periode = 0;
		tmp->next->carry = 0;
		while (++k < 16)
			tmp->next->reg[k] = 0;
		tmp->next->next = NULL;
		tmp = tmp->next;
	}
}
