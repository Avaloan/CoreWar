/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 06:01:56 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/27 06:13:05 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_apply_option(t_env *e, char *argv, int i)
{
	if (e->option == 1)
		return (ft_apply_dump(e, i));
	else if (e->option == 2)
		return (ft_apply_number(e, i));
	return (0);
}
