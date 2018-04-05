/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 06:01:56 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/31 06:08:45 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_apply_option(t_env *e, char *argv, int i)
{
	int	k;
	int	tmp;

	tmp = e->option;
	e->option = 0;
	k = -1;
	while (argv[++k] != '\0')
		if (!ft_isdigit(argv[k]))
			return (0);
	if (tmp == 1)
	{
		e->dump_on = ft_atoi(argv);
		if (ft_strcmp(ft_itoa(e->dump_on), argv))
			return (0);
		return (1);
	}
	else if (tmp == 2)
	{
		e->forced_nb_for_pl = ft_atou(argv);
		if (ft_strcmp(ft_utoa_base(e->forced_nb_for_pl, 10), argv))
			return (0);
		return (1);
	}
	return (0);
}
