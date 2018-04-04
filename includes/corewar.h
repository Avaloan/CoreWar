/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 04:36:59 by snedir            #+#    #+#             */
/*   Updated: 2018/03/23 04:47:18 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# define OP_CODE e->op_code
# define BAD_CODING_BYTE 45
# define REG_NUMBER 16

typedef struct				s_params
{
	int						nb_params_max;
	int						i;
	unsigned char			coding_byte;
	int						total_size;
}							t_params;

typedef struct				s_args_value
{
	unsigned char			reg;
	int						dir;
	short					ind;
	char					type;
}							t_args_value;

typedef struct				s_process
{
	unsigned int			pc;
	unsigned int			reg[REG_NUMBER];
	char					alive;
	int						countdown;
	char					carry;
}							t_process;


typedef struct				s_env
{
	int						nbr_of_players;
	struct s_op 			*op_tab;
	t_process				*pc_list;
	unsigned char			*arena;
}							t_env;

typedef struct				s_op
{
	void					*(op)(s_env *, t_process *pc, t_args_value args[3]);
	int						nb_params;
	int						dir_size;
	unsigned char			coding_byte;
	char					*args_type;
}							t_op;
#endif
