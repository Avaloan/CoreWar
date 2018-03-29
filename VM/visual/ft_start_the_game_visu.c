/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_the_game_visu.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 06:16:10 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/29 04:56:30 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_start_the_game_visu(t_env *e)
{
	if (ft_fill_arena(e) == 0)
		return (0);
	if (ft_fill_info(e) == 0)
		return (0);
	wrefresh(e->vi->arena);
	wrefresh(e->vi->info);
//	getch();
	return (1);
}
