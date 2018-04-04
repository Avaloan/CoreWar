/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 05:15:24 by snedir            #+#    #+#             */
/*   Updated: 2018/03/28 04:12:20 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"
#include <math.h>
#include <stdlib.h>

t_op_info	 g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
	 "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
	 "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
	 "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
	 "load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
	 "store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
	 "long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

void dec_to_bin(int dec, unsigned char *bin_num, int index, int size)
{
	int i;
	int limit;

	i = index - 1;// - 500;
	limit = 8;
	printf("index		: %d\n", i);
	if (dec == 0)
	{
		while (--limit >= 0)
		{
//			printf("i %d\n", i);
			bin_num[i] = '0';
			i--;
		}
	}
	while (dec > 0 && i >= 0)
	{
//		printf("dec = %d, i = %d\n", dec, i);
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
//				printf("limit : %d || i : %d\n", limit, i);
				bin_num[i] = '0';
				limit--;
				i--;
			}
		/*if (i >= 0 && dec == 0)
		{
			while (i >= 0)
			{
				bin_num[i] = '0';
				printf("fff\n");
				i++;
			}
		
		}*/
	}
}

void	write_4_bytes(t_env *e, unsigned int input, int arg_size)
{
	unsigned int i = 0;
	unsigned int tmp = 0;

	/*if (arg_size == 1) ?
		e->arena[pc->pos] = (unsigned char)input;
		return;*/
	while (input && i < arg_size)
	{
		tmp = input >> 8 * arg_size - 1;
		e->arena[pc->pos] = tmp;
		i++;
		input = input << 8;
	}
}

void	write_2_bytes(t_env *e, unsigned short input, int arg_size)
{
	unsigned int i = 0;
	unsigned short tmp = 0;

	/*if (arg_size == 1) ?
		e->arena[pc->pos] = (unsigned char)input;
		return;*/
	while (input && i < arg_size)
	{
		tmp = input >> 8 * arg_size - 1;
		e->arena[pc->pos] = tmp;
		i++;
		input = input << 8;
	}
}

unsigned int bin_to_dec(int size, unsigned char *number, unsigned int array_size)
{
	unsigned int result;
	int i;

	i = 0;
	result = 0;
	while (i < array_size)
	{
		if (number[i] == '1')
			result += pow(2, ((size * 8) - i) - 1);
//		printf("i : %d || size : %d || size * (7-i) : %d || result : %zd\n", i, size, ((size * 8) - i), result);
		i++;
	}
	return (result);
}

/*
 **	fonction lecture bidule doit etre lancée pour
 ** les indirects aussi faire les modifs
 */

int	read_nb_bytes(t_env *e, int arg_size, t_process *process, int offset)
{
	int i;
	int iter;
	unsigned char *tab;
	unsigned int stock;

	i = 1;
	stock = 0;
	iter = 1;
	//printf("ARG SIZE%d\n", arg_size);
	tab = ft_memalloc(sizeof(unsigned char) * arg_size * 8);
	//printf("pc : %d | e->arena[process->pc] : %d | i : %d\n", process->pc, e->arena[process->pc], i);
	while (i < arg_size + 1)
	{
		stock = e->arena[process->pc + iter + offset];
	//	printf("stock : %d\n", stock);
		dec_to_bin(stock, tab, i * 8, arg_size * 8);
		i++;
		printf("tab		: %s\n", tab);
		iter++;
	}
	stock = bin_to_dec(arg_size, tab, arg_size * 8);
	printf("arg		: %zd\n", stock);
	free(tab);
	return (stock);
}

 /*
 **	Bcp de valeurs en dur faire attention
 */

void get_args_value(t_args_value args[3], int arg_type, int num_param, int opcode, t_process *pc, t_env *e, t_params *p) //pendant le check_coding byte
{
	if (arg_type == 1)
	{
		args[num_param].reg = read_nb_bytes(e, 1, pc, p->total_size);
		//printf("reg : %d\n", args[num_param].reg);
		if (args[num_param].reg <= 0 || args[num_param].reg > REG_NUMBER)
			printf("		REG_NUMBER INVALID\n");//faire avancer le pc de 1
				args[num_param].type = 'r';
		p->total_size += 1;
		//printf("p->total_size : %d\n", p->total_size);
	}
	if (arg_type == 4)
	{
		args[num_param].ind = read_nb_bytes(e, 2, pc, p->total_size);
		//printf("ind : %d\n", args[num_param].ind);
		args[num_param].type = 'i';
		p->total_size += 2;
	}
	if (arg_type == 2)
	{
		//printf("DIR SIZE %d\n", g_op_tab[opcode].dir_size);
		if (g_op_tab[opcode].dir_size == 0)
		{
			args[num_param].dir = read_nb_bytes(e, 4, pc, p->total_size);
		//printf("dir : %d\n", args[num_param].dir);
			p->total_size += 4;
		}
		else
			args[num_param].dir = read_nb_bytes(e, 2, pc, p->total_size);
		//printf("dir : %d\n", args[num_param].dir);
		args[num_param].type = 'd';
		p->total_size += 2;
	}
}

	int	fonction_check_coding_byte(t_env *e, t_params *p, t_args_value args[3], int opcode, t_process *pc)
{
	int tmp;

	if (p->i == p->nb_params_max && p->coding_byte != 0)
		return (BAD_CODING_BYTE);
	else if (p->i == p->nb_params_max && p->coding_byte == 0)
		return (1);
	tmp = (p->coding_byte >> 6);
	//printf("tmp : %d\n", tmp);
	if (tmp == 3)
		tmp = 4;
	if ((tmp = tmp & g_op_tab[opcode].arg_type[p->i]) > 0)
	{
		p->coding_byte <<= 2;
		p->i++;
		if (fonction_check_coding_byte(e, p, args, opcode, pc) == 1)
		{
			p->i--;
			get_args_value(args, tmp, p->i, opcode, pc, e, p);
			return (1);
		}
	}
	return (BAD_CODING_BYTE);
}

void	fonction_lancement_op(t_env *e, t_process *process)
{
	unsigned char opcode;
	t_params params;
	t_args_value args[3];

	opcode = e->arena[process->pc] - 1;
	printf("opcode		: %d\n", opcode);
	params.nb_params_max = g_op_tab[opcode].nb_param;
	params.i = 0;
	printf("octal		: %d\n", g_op_tab[opcode].octal);
	if (g_op_tab[opcode].octal == 1)
	{
		process->pc += 1;
		params.coding_byte = e->arena[process->pc];
		printf("octet codage	: %x\n", params.coding_byte);
		if (fonction_check_coding_byte(e, &params, args, opcode, process) == BAD_CODING_BYTE)
			return ; //faire avancer le pc de 1
	}
	process->pc += params.total_size;
	//e->op_tab[opcode].op(e, process, args);
}
