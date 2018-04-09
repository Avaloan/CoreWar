/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 05:15:24 by snedir            #+#    #+#             */
/*   Updated: 2018/04/09 05:22:49 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

/*t_op_info	g_op_tab[17] =
{
	{live, "live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{ld, "ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{st, "st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{add, "add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{sub, "sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{_and, "and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
	 "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{_or, "or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
	 "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{_xor, "xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
	 "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{zjmp, "zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{ldi, "ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
	 "load index", 1, 1},
	{sti, "sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
	 "store index", 1, 1},
	{_fork, "fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{lld, "lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{lldi, "lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
	 "long load index", 1, 1},
	{lfork, "lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{aff, "aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{NULL, 0, 0, {0}, 0, 0, 0, 0, 0}
};*/

void			dec_to_bin(int dec, unsigned char *bin_num, int index, int size)
{
	int				i;
	int				limit;

	i = index - 1;
	limit = 8;
	if (dec == 0)
	{
		while (--limit >= 0)
		{
			bin_num[i] = '0';
			i--;
		}
	}
	while (dec > 0 && i >= 0)
	{
		if (dec % 2 == 0)
			bin_num[i] = '0';
		else
			bin_num[i] = '1';
		dec /= 2;
		i--;
		limit--;
		if (dec == 0 && limit > 0)
			while (limit > 0 && i < size)
			{
				bin_num[i] = '0';
				limit--;
				i--;
			}
	}
}

void			write_4_bytes(t_env *e, unsigned int input, t_process *pc, unsigned int off)
{
	unsigned int	i;
	unsigned int	tmp;

	i = 0;
	tmp = 0;
	while (input && i < INT_SIZE)
	{
		tmp = input >> 8 * (INT_SIZE - 1);
		e->arena[pc->pc + off + i] = tmp;
		e->written_by[pc->pc + off + i] = pc->from_pl;
		i++;
		input = input << 8;
	}
}

void			write_2_bytes(t_env *e, unsigned short input, t_process *pc, unsigned int off)
{
	unsigned int	i;
	unsigned short	tmp;

	i = 0;
	tmp = 0;
	while (input && i < INT_SIZE - 2)
	{
		tmp = input >> 8;
		e->arena[pc->pc + off + i] = tmp;
		e->written_by[pc->pc + off + i] = pc->from_pl;
		i++;
		input = input << 8;
	}
}

unsigned int	bin_to_dec(int size, unsigned char *number, unsigned int array_size)
{
	unsigned int	result;
	int				i;

	i = 0;
	result = 0;
	while (i < array_size)
	{
		if (number[i] == '1')
			result += pow(2, ((size * 8) - i) - 1);
		i++;
	}
	return (result);
}

int				read_nb_bytes(t_env *e, int arg_size, t_process *process, unsigned int offset)
{
	int				i;
	int				iter;
	unsigned char	*t;
	unsigned int	stock;

	i = 1;
	stock = 0;
	iter = 1;
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
	return (stock);
}

void			get_args_value(t_args_value args[3], int arg_type, int num_param, int opcode, t_process *pc, t_env *e, t_params *p)
{
	if (arg_type == 1)
	{
		args[num_param].reg = read_nb_bytes(e, 1, pc, p->total_size);
		if (args[num_param].reg <= 0 || args[num_param].reg > REG_NUMBER)
			printf("		REG_NUMBER INVALID\n");//faire avancer le pc de 1
		p->total_size += 1;
		args[num_param].type = 'r';
	}
	if (arg_type == 4)
	{
		args[num_param].ind = read_nb_bytes(e, 2, pc, p->total_size);
		args[num_param].type = 'i';
		p->total_size += 2;
	}
	if (arg_type == 2)
	{
		if (g_op_tab[opcode].dir_size == 0)
		{
			args[num_param].dir = read_nb_bytes(e, 4, pc, p->total_size);
			p->total_size += 4;
		}
		else
		{
			args[num_param].dir = read_nb_bytes(e, 2, pc, p->total_size);
			p->total_size += 2;
		}
		args[num_param].type = 'd';
	}
}

void			init_t_args(t_args_value args[3])
{
	int				i;

	i = -1;
	while (++i < 3)
	{
		args[i].reg = 0;
		args[i].dir = 0;
		args[i].ind = 0;
		args[i].type = 0;
	}
}

void			init_t_params(t_params *params)
{
	params->nb_params_max = 0;
	params->i = 0;
	params->coding_byte = 0;
	params->total_size = 0;
}

int				check_coding_byte(t_env *e, t_params *p, t_args_value args[3], int opcode, t_process *pc)
{
	int				tmp;

	if (p->i == p->nb_params_max && p->coding_byte != 0)
		return (BAD_CODING_BYTE);
	else if (p->i == p->nb_params_max && p->coding_byte == 0)
		return (1);
	tmp = (p->coding_byte >> 6);
	if (tmp == 3)
		tmp = 4;
	if ((tmp = tmp & g_op_tab[opcode].arg_type[p->i]) > 0)
	{
		p->coding_byte <<= 2;
		get_args_value(args, tmp, p->i, opcode, pc, e, p);
		p->i++;
		return (check_coding_byte(e, p, args, opcode, pc));
	}
	return (BAD_CODING_BYTE);
}

int				ft_operations(t_env *e, t_process *process)
{
	unsigned char	opcode;
	t_params		params;
	t_args_value	args[3];

	init_t_args(args);
	init_t_params(&params);
	opcode = e->arena[process->pc] - 1;
	//printf("opcode = %x\n", opcode);
	params.nb_params_max = g_op_tab[opcode].nb_param;
	if (g_op_tab[opcode].octal == 1)
	{
		process->pc += 1;
		params.coding_byte = e->arena[process->pc];
		if (check_coding_byte(e, &params, args, opcode, process) == BAD_CODING_BYTE)
			return (0);
	}
	else
	{
		params.total_size = (g_op_tab[opcode].dir_size) ? 2 : 4;
		args[0].dir = read_nb_bytes(e, params.total_size, process, 0);
	}
	//printf("CASE READ = %.2x\n", e->arena[process->pc]);
	g_op_tab[opcode].op(e, process, args);
	//printf("param_size = %i\n", params.total_size);
	process->pc += params.total_size + 1;
	//printf("new read = [%.2x]\n", e->arena[process->pc]);
	return (1);
}
