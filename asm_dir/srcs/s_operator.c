/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 03:08:43 by snedir            #+#    #+#             */
/*   Updated: 2018/04/28 04:28:31 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		operator_all(t_env *e, int start, unsigned char opcode, int sl)
{
	unsigned char	size_command;

	size_command = 1;
	if (opcode > 9)
		size_command = 2;
	start += skip_space(e->stock + e->count + start);
	if (!check_nb_param(e, start, sl, opcode - 1) ||
			!valid_param(e, start, opcode - 1))
		return (0);
	add_command(e, &opcode, size_command);
	menu_args_coding_byte(e, start, opcode - 1);
	return (1);
}
