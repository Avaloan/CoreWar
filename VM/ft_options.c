/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 05:51:32 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/27 06:43:11 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_dump_next(t_env *e)
{
}

int	ft_number_next(t_env *e)
{

}

int	ft_visual(e)
{
	int	test;

	e->root = sqrt(MEM_SIZE);
	test = MEM_SIZE % e->root;
	if (test != 0 || e->root < nb_de_donnes_a_placer_dans_la_window_info_sur_lignes_differentes)
		return (0);
	e->vi = 1;
	e->vi->border = 3;
	e->vi->mx = (3 * e->root) + e->vi->border;
	e->vi->my = (e->root) + 1;
	initscr();
	e->vi->arena = newwin(e->vi->my, e->vi->mx, 0, 0);
	e->vi->info = newwin(e->vi->my, e->vi->mx + 80, 0, e->vi->mx + 2);
	box(e->vi->arena, 0, 0);
	box(e->vi->info, 0, 0);
	return (1);
}

int	ft_options(t_env *e, char *argv)
{
	if (ft_strcmp("-dump", argv))
		return (ft_dump_next(e));
	if (ft_strcmp("-n", argv))
		return (ft_number_next(e));
	if (ft_strcmp("-v", argv))
		return (ft_visual(e));
	return (1);
}
