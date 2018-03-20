/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 05:15:24 by snedir            #+#    #+#             */
/*   Updated: 2018/03/14 05:40:59 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/corewar.h"

void	live(t_env *e, int direct, int not_used, int not_used2)
{
}

typedef struct s_params
{
	int nb_params_max;
	int i;
	unsigned char coding_byte;
	int total_size;
}t_params;

typedef struct s_args_value
{
	int reg;
	int dir;
	int ind;
}t_args_value;

void get_args_value(t_args_value args[3], int arg_type, int num_param) //pendant le check_coding byte
{
	if (arg_type == 1)
		args[num_param].reg = fonction_lecture_arg_check_error();
	if (arg_type == 4)
		args[num_param].ind = fonction_lecture_arg_check_error();
	if (arg_type == 2)
		args[num_param].dir = fonction_lecture_arg_check_error();
}

void fonction_lancement_op(t_env *e, t_process *process)
{
	int opcode;
	t_params params;
	t_args_value args[3];

	opcode = e->arena[process->pc]
	params.nb_params_max = e->op_tab[opcode].nb_params;
	params.i = 0;
	params.coding_byte = (unsigned char)e->arena[process->pc + 1];
	if (fonction_check_coding_byte(&params, args) == BAD_CODING_BYTE)
		return (1); //faire avancer le pc de 1
	e->op_tab[opcode].op(e, pc, args);


}

int fonction_check_coding_byte(t_env *e, t_params &p, t_args_value args[3], int opcode)
{
	int tmp;

	if (p->i == p->nb_params_max && p->coding_byte != 0)
		return (BAD_CODING_BYTE);
	else
		return (1)
	if (tmp = ((p->coding_byte >> 6) & (e->op_tab[opcode].arg_type[p->i]))
	{
		p->coding_byte <<= 2;
		p->i++;
		if (fonction_check_coding_byte(e, p, args, opcode) == 1)
		{
			p->total_size += taille_arg;
			get_args_value(args, tmp, p->i);
		}
		return (1);
	}
	return (BAD_CODING_BYTE);
}