/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_visu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 04:03:34 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/28 04:48:20 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

void	ft_end_visu(t_env *e)
{
	if (e->vi)
	{
		if (e->vi->arena)
			wclear(e->vi->arena);
		if (e->vi->info)
			wclear(e->vi->info);
		if (e->vi->arena)
			delwin(e->vi->arena);
		if (e->vi->info)
			delwin(e->vi->info);
		free(e->vi);
	}
	endwin();
}
