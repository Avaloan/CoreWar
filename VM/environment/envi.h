/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envi.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 01:43:22 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/20 05:02:31 by gquerre          ###   ########.fr       */
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
#define CYCLE_DELTA				
#define NBR_LIVE				
#define MAX_CHECKS				

#define T_REG					1
#define T_DIR					2
#define T_IND					3
#define T_LAB					8

#define	NAME_LENGTH				128
#define COMMENT_LENGTH			2048
#define COREWAR					0xea83f3

/*
** PLAYERS
*/
#define NUM_PLAYER				1
#define ID						2
#define	LIVES_PERIODE			3
#define	TOTAL_LIVES				4
#define	LAST_LIVE				5

/*
**	CHAMPIONS
*/

typedef struct					s_champ
{
	char						*champ;
	typedef struct s_champ		next;
}								t_champ;

/*
** PROCESS
*/
typedef struct					s_process
{
	int							pc;
	int							reg[16];
	int							waiting;
	int							live_during_periode;
	typedef struct s_process	next;
	int							carry;
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
	t_champ						*champions;

}								t_env;

#define CYCLE_TO_DIE
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
