/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 05:15:24 by snedir            #+#    #+#             */
/*   Updated: 2018/04/05 06:47:14 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

t_op_info	 g_op_tab[17] =
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
};

void dec_to_bin(int dec, unsigned char *bin_num, int index, int size)
{
	int i;
	int limit;

	i = index - 1;// - 500;
	limit = 8;
	//printf("index		: %d\n", i);
	if (dec == 0)
	{
		while (--limit >= 0)
		{
			//printf("i %d\n", i);
			bin_num[i] = '0';
			i--;
		}
	}
	while (dec > 0 && i >= 0)
	{
		//printf("dec = %d, i = %d\n", dec, i);
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

void	write_4_bytes(t_env *e, unsigned int input, int arg_size, t_process *pc)
{
	unsigned int i = 0;
	unsigned int tmp = 0;

	while (input && i < arg_size)
	{
		tmp = input >> 8 * (arg_size - 1);
		e->arena[pc->pc] = tmp;
		i++;
		input = input << 8;
	}
}

void	write_2_bytes(t_env *e, unsigned short input, int arg_size, t_process *pc)
{
	unsigned int i = 0;
	unsigned short tmp = 0;

	while (input && i < arg_size)
	{
		tmp = input >> 8 * (arg_size - 1);
		e->arena[pc->pc] = tmp;
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
	unsigned char *t;
	unsigned int stock;

	i = 1;
	stock = 0;
	iter = 1;
	printf("ARG SIZE %d\n", arg_size * 8);
	t = (unsigned char*)ft_memalloc(sizeof(char) * (arg_size * 8));
	while (i < arg_size + 1)
	{
		stock = e->arena[process->pc + iter + offset];
		printf("stock : %d || pc %d + iter %d + offset %d\n", stock, process->pc, iter, offset);
		//printf("offset : %d\n", offset);
		dec_to_bin(stock, t, i * 8, arg_size * 8);
		//printf("i b4	: %d\n", i);
		i++;
		iter++;
	}
	stock = bin_to_dec(arg_size, t, arg_size * 8);
	printf("arg		: %zd\n", stock);
	free(t);
	t = NULL;
	return (stock);
}

 /*
 **	Bcp de valeurs en dur faire attention
 */

void get_args_value(t_args_value args[3], int arg_type, int num_param, int opcode, t_process *pc, t_env *e, t_params *p) //pendant le check_coding byte
{
	printf("tota_size %d\n", p->total_size);
	if (arg_type == 1)
	{
		p->total_size += 1;
		args[num_param].reg = read_nb_bytes(e, 1, pc, p->total_size);
		if (args[num_param].reg <= 0 || args[num_param].reg > REG_NUMBER)
			printf("		REG_NUMBER INVALID\n");//faire avancer le pc de 1
				args[num_param].type = 'r';
		printf("reg : %d\n", args[num_param].reg);
		//printf("p->total_size : %d\n\n", p->total_size);
	}
	if (arg_type == 4)
	{
		p->total_size += 2;
		args[num_param].ind = read_nb_bytes(e, 2, pc, p->total_size);
		args[num_param].type = 'i';
		printf("ind : %d\n", args[num_param].ind);
		//printf("p->total_size : %d\n\n", p->total_size);
	}
	if (arg_type == 2)
	{
		printf("DIR SIZE %d\n", g_op_tab[opcode].dir_size);
		if (g_op_tab[opcode].dir_size == 0)
		{
			args[num_param].dir = read_nb_bytes(e, 4, pc, p->total_size);
			printf("dir : %d\n", args[num_param].dir);
			p->total_size += 4;
		}
		else
			args[num_param].dir = read_nb_bytes(e, 2, pc, p->total_size);
		printf("dir : %d\n", args[num_param].dir);
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
	printf("octal tmp : %d\n", tmp);
	if (tmp == 3)
		tmp = 4;
	if ((tmp = tmp & g_op_tab[opcode].arg_type[p->i]) > 0)
	{
		printf("mmh : %d\n", tmp);
		p->coding_byte <<= 2;
		p->i++;
		if (fonction_check_coding_byte(e, p, args, opcode, pc) == 1)
		{
			p->i--;
			get_args_value(args, tmp, p->i, opcode, pc, e, p);
			return (1);
		}
	}
	printf("Error ?\n");
	return (BAD_CODING_BYTE);
}

void	ft_operations(t_env *e, t_process *process)
{
	unsigned char opcode;
	t_params params;
	t_args_value args[3];

	params.total_size = 0;
	opcode = e->arena[process->pc] - 1;
	printf("opcode		: %d\nname		: %s\n", opcode, g_op_tab[opcode].name);
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
		process->pc -= 1;
	}
	//printf("dg\n");
	//g_op_tab[opcode].op(e, process, args);
	process->pc += params.total_size;
}
