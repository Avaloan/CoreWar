/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 00:53:20 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/22 04:41:55 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".h"

void	ft_init_checks(t_env *e)
{
	e->cycles_to_die = CYCLE_TO_DIE;
	e->cycles = 0;
	e->cycles_periodes = 0;
	e->checks_done = 0;
	e->lives_periode = 0;
}
