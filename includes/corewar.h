/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 04:36:59 by snedir            #+#    #+#             */
/*   Updated: 2018/03/19 00:58:45 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
//# include "lib_corewar.h" // lib speciale pour le CoreWar
# define OP_CODE e->op_code

typedef struct				s_process
{
	unsigned int			pc;
	int						reg[16];
	char					alive;
	int						countdown;
	char					carry;
}							t_process;

typedef struct				s_op
{
	void					*(op)(s_env *, t_process *pc, t_args_value args[3]);
	int						nb_params;
	int						dir_size;
	int						coding_byte;
	char					*args_type;
}							t_op;

typedef struct				s_env
{
	int						nbr_of_players;
	t_op 					*op_tab;
	t_process				*pc_list;
	void					*arena;
}							t_env;
#endif
