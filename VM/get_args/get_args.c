/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 05:15:24 by snedir            #+#    #+#             */
/*   Updated: 2018/04/15 19:53:06 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int				read_nb_bytes(t_env *e, int arg_size, t_process *process, int offset)
{
	int				i;
	int				iter;
	unsigned char	*t;
	unsigned int	stock;

	i = 1;
	stock = 0;
	iter = 1;
//	printf("arg_size_from_read = %i\n", arg_size);
	t = (unsigned char*)ft_memalloc(sizeof(char) * (arg_size * 8));
	while (i < arg_size + 1)
	{
		stock = e->arena[process->pc + iter + offset];
		dec_to_bin(stock, t, i * 8, arg_size * 8);
		i++;
		iter++;
	}
	stock = bin_to_dec(arg_size, t, arg_size * 8);
	free(t);
	t = NULL;
//	printf("stock = %u\n", stock);
	return (stock);
}

int			get_reg_value(t_args_value args[3], t_process *pc, t_env *e,
t_params *p)
{
	args[p->num_param].reg = read_nb_bytes(e, 1, pc, p->total_size);
	if (args[p->num_param].reg <= 0 || args[p->num_param].reg > REG_NUMBER)
		return (REG_INVALID);
	p->total_size += 1;
	args[p->num_param].type = 'r';
	return (1);	
}

void		get_ind_value(t_args_value args[3], t_process *pc, t_env *e,
t_params *p)
{
	args[p->num_param].ind = read_nb_bytes(e, 2, pc, p->total_size);
	args[p->num_param].type = 'i';
	p->total_size += 2;
}

void		get_dir_value(t_args_value args[3], t_process *pc, t_env *e,
t_params *p)
{
	if (g_op_tab[p->opcode].dir_size == 0)
	{
		args[p->num_param].dir = read_nb_bytes(e, 4, pc, p->total_size);
		p->total_size += 4;
	}
	else
	{
		args[p->num_param].dir_short = read_nb_bytes(e, 2, pc, p->total_size);
		p->total_size += 2;
	}
	args[p->num_param].type = 'd';
}

int			get_args_value(t_args_value args[3],t_process *pc, t_env *e,
t_params *p)
{
	if (p->arg_type == 1)
	{
		if (get_reg_value(args, pc, e, p) == REG_INVALID)
			return (REG_INVALID);
	}
	else if (p->arg_type == 4)
		get_ind_value(args, pc, e, p);
	else if (p->arg_type == 2)
		get_dir_value(args, pc, e, p);
	return (1);
}
