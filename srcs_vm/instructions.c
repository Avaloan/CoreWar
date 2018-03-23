/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 05:15:24 by snedir            #+#    #+#             */
/*   Updated: 2018/03/23 05:57:19 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/corewar.h"


int	fonction_lecture_arg_check_error(t_env *e, int opcode, int arg_size, t_process *pc)
{
	int i;
	int stock;

	i = 0;
	stock = 0;
	// Faire selon la taille de arg_size utiliser les puissances et faire des additions pour recup l'arg
	while (i < arg_size)
	{
		stock
void get_args_value(t_args_value args[3], int arg_type, int num_param, int opcode, t_process *pc) //pendant le check_coding byte
{
	if (arg_type == 1)
	{
		args[num_param].reg = fonction_lecture_arg_check_error();
		args[num_param].type = 'r';
	}
	if (arg_type == 4)
	{
		args[num_param].ind = fonction_lecture_arg_check_error();
		args[num_param].type = 'i';
	}
	if (arg_type == 2)
	{
		args[num_param].dir = fonction_lecture_arg_check_error();
		args[num_param].type = 'd';
	}
}


int fonction_check_coding_byte(t_env *e, t_params *p, t_args_value args[3], int opcode, t_process *pc)
{
	int tmp;

	if (p->i == p->nb_params_max && p->coding_byte != 0)
		return (BAD_CODING_BYTE);
	else
		return (1);
	tmp = (p->coding_byte >> 6) & (e->op_tab[opcode].args_type[p->i]);
	if (tmp == 3)
		tmp = 4;
	if (tmp > 0)
	{
		p->coding_byte <<= 2;
		p->i++;
		if (fonction_check_coding_byte(e, p, args, opcode) == 1)
		{
			p->total_size += (int)e->op_tab[opcode].args_type[p->i - 1];
			get_args_value(args, tmp, p->i, opcode, pc);
			return (1);
		}
	}
	return (BAD_CODING_BYTE);
}

void fonction_lancement_op(t_env *e, t_process *process)
{
	unsigned char opcode;
	t_params params;
	t_args_value args[3];

	opcode = e->arena[process->pc];
	params.nb_params_max = e->op_tab[opcode].nb_params;
	params.i = 0;
	params.coding_byte = e->arena[process->pc + 1];
	if (fonction_check_coding_byte(e, &params, args, opcode, process) == BAD_CODING_BYTE)
		return ; //faire avancer le pc de 1
	e->op_tab[opcode].op(e, process, args);
}
