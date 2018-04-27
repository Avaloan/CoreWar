/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 03:08:43 by snedir            #+#    #+#             */
/*   Updated: 2018/04/27 03:42:37 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		st_operator(t_env *e, int start, int sl)
{
	start += skip_space(e->stock + e->count + start);
	if (!check_nb_param(e, start, sl, 2) || !valid_param(e, start, 2))
		return (0);
	menu_args_coding_byte(e, start, 3);
	return (1);
}
/*
sub_ope()

sti_ope()*/
