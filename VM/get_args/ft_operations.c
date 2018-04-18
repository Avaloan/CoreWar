/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 05:15:24 by snedir            #+#    #+#             */
/*   Updated: 2018/04/18 18:32:29 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int				check_coding_byte(t_env *e, t_params *p, t_args_value args[3],
		t_process *pc)
{
	static int	a = 1;

	if (a == BAD_CODING_BYTE)
		a = BAD_CODING_BYTE;
	else
		a =  1;
	if (p->num_param == p->nb_params_max && p->coding_byte != 0)
		return (BAD_CODING_BYTE);
	else if (p->num_param == p->nb_params_max && p->coding_byte == 0)
		return (a);
	p->arg_type = (p->coding_byte >> 6);
	if (p->arg_type == 3)
		p->arg_type = 4;
	//if ((p->arg_type, /* && g_op_tab[p->opcode].arg_type[p->num_param]*/))
	if (p->num_param < p->nb_params_max)
		{
		p->coding_byte <<= 2;
		//printf("In coding byte %d\n", p->total_size);
		if (get_args_value(args, pc, e, p) == REG_INVALID)
		{
			a = BAD_CODING_BYTE;
			//printf("la diff in coding byte %d // pos arena = [%d]\n", p->total_size, pc->pc);
		}
	//	printf("yolo\n");
		p->num_param++;
		return (check_coding_byte(e, p, args, pc));
	}
	return (a);
}

int				ft_operations(t_env *e, t_process *process)
{
	t_params		params;
	t_args_value	args[3];

	init_t_args(args);
	init_t_params(&params);
	if ((params.opcode = e->arena[process->pc] - 1) > 17)
		return (0);
	params.nb_params_max = g_op_tab[params.opcode].nb_param;
	if (g_op_tab[params.opcode].octal == 1)
	{
		process->pc = (process->pc + 1) % MEM_SIZE;
		params.coding_byte = e->arena[process->pc];
		if (check_coding_byte(e, &params, args, process) == BAD_CODING_BYTE)
		{
			process->pc = (process->pc + params.total_size) % MEM_SIZE;
			return (0);
		}
	}
	else
	{
		params.total_size = (g_op_tab[params.opcode].dir_size) ? 2 : 4;
		if (params.total_size == 4)
			args[0].dir = read_nb_bytes(e, params.total_size, process, 0);
		else
			args[0].dir_short = read_nb_bytes(e, params.total_size, process, 0);
	}
	process->pc = process->pc % MEM_SIZE;
	g_op_tab[params.opcode].op(e, process, args);
	if (params.opcode + 1 != 9)
		process->pc += (params.total_size + 1);
	process->pc = process->pc % MEM_SIZE;
	return (1);
}
