/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 03:08:43 by snedir            #+#    #+#             */
/*   Updated: 2018/04/28 03:02:12 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		st_operator(t_env *e, int start, int sl)
{
	unsigned char lel;

	lel = 3;
	start += skip_space(e->stock + e->count + start);
	if (!check_nb_param(e, start, sl, 2) || !valid_param(e, start, 2))
		return (0);
	add_command(e, &lel, 1);
	menu_args_coding_byte(e, start, 3);
	return (1);
}
/*
sub_ope()

sti_ope()*/
