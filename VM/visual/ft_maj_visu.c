/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maj_visu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 02:19:28 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/29 07:37:45 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_maj_visu(t_env *e)
{
	if (ft_fill_arena(e) == 0 || ft_fill_info(e) == 0)
		return (0);
	wrefresh(e->vi->arena);
	wrefresh(e->vi->info);
	return (1);
}
