/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 05:51:32 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/29 04:50:39 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

/*int	ft_dump_next(t_env *e)
{
	e->option = 1;
}

int	ft_number_next(t_env *e)
{
	e->option = 2;
}
*/
int	ft_options(t_env *e, char *argv)
{
//	if (ft_strcmp("-dump", argv))
//		return (ft_dump_next(e));
//	if (ft_strcmp("-n", argv))
//		return (ft_number_next(e));
	if (ft_strcmp("-v", argv) == 0)
		return (ft_visual(e));
	return (1);
}
