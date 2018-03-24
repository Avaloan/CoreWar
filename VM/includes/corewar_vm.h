/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 05:54:02 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/24 05:54:07 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**
*/

#define	MEM_SIZE		(4 * 1024)
#define IDX_MOD			(MEM_SIZE / 8)
#define REG_NUMBER		16

/*
** ENVIRONMENT
*/

#define	MAX_PLAYERS				4
#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10

#define T_REG					1
#define T_DIR					2
#define T_IND					3
#define T_LAB					8

#define	NAME_LENGTH				128
#define COMMENT_LENGTH			2048
#define COREWAR					0xea83f3

/*
** PROCESS
*/

typedef struct					s_process
{
	int							pc;
	int							reg[REG_NUMBER];
	int							waiting;
	int							lives_during_periode;
	typedef struct s_process	next;
	int							carry;
	int							to_exec;
}								t_process;

/*
** PLAYERS
*/

typedef struct					s_player
{
	int							num_player;
	int							id;
	int							lives_periode;
	int							total_lives;
	int							last_live;
	char						*name;
	char						*comment;
}								t_player;

/*
** ENVIRONMENT
*/

typedef struct					s_env
{
	int							nb_of_pl;
	int							nb_of_check;
	int							cycle;
	char						carry;
	void						*(op_code)(s_env *, int, int, int);
	t_process					*pc_list; 
	void						*arena;
	t_players					*players;
	int							cycles_to_die;
	int							cycles;
	int							cycles_periode;
	int							checks_done;
	int							lives_periode;
}								t_env;

/*
**	FONCTIONS
*/

int								ft_create_arena(t_env *e);
int								ft_how_many_pl(t_env *e, int *argc, char **argv);
int								ft_init_player(t_env *e, char *argv);
int								ft_init_process(t_env *e);
int								ft_error(t_env *e);
int								ft_finish(t_env *e);
int								ft_game_runner(t_env *e);
int								ft_play_turn(t_env *e);
int								ft_add_pc(t_env *e, t_process *father, int i);//Operations pour fork
