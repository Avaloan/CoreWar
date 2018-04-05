/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 04:36:59 by snedir            #+#    #+#             */
/*   Updated: 2018/04/05 02:33:30 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# define OP_CODE e->op_code
# define BAD_CODING_BYTE 45
# define REG_NUMBER 16
# define IDX_MOD 512

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
	void					(*op)(t_env *e, t_process *pc, t_args_value args[3]);
	int						nb_params;
	int						dir_size;
	unsigned char			coding_byte;
	char					*args_type;
}							t_op;

int							read_nb_bytes(t_env *, int, t_process *, int);
void						write_2_bytes(t_env *, unsigned short, int, t_process *);
void						write_4_bytes(t_env *, unsigned int, int, t_process *);
void						fonction_lancement_op(t_env *, t_process *);
void						st(t_env *, t_process *, t_args_value args[3]);

#endif
