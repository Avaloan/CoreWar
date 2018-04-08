/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 05:51:32 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/07 06:00:31 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_options(t_env *e, char *argv)
{
	if (!(ft_strcmp("-dump", argv)))
		e->option = 1;
	if (!(ft_strcmp("-n", argv)))
		e->option = 2;
//	if (!(ft_strcmp("-dump_by", argv)))
//		e->dump_on = 3;
	if (ft_strcmp("-v", argv) == 0)
		return (ft_visual(e));
	return ((e->option) ? 1 : 0);
}
