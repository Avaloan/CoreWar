/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envi.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 01:43:22 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/14 06:13:24 by gquerre          ###   ########.fr       */
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

#define	MAX_PLAYERS		4
#define CYCLE_TO_DIE	1536
#define CYCLE_DELTA
#define NBR_LIVE
#define MAX_CHECKS

#define T_REG			1
#define T_DIR			2
#define T_IND			3
#d efine T_LAB			8

#define	NAME_LENGTH		128
#define COMMENT_LENGTH	2048
#define COREWAR			0xea83f3

typedef struct			s_env
{
	int					nb_of_pl;
	int					nb_of_check;
	int					cycle;
	char				carry;
	void				*(op_code)(s_env *, int, int, int);
	t_process			*pc_list; 
	void				*arena;
}						t_env

/*
** PLAYERS
*/

typedef struct			s_player
{
	int					num_player;
	int					lives_during_periode;
	int					lives_total;
	int					
}						t_player;

/*
** PROCESS
*/

typedef struct			s_process
{
	int					pc;
	int					reg[16];
	int					waiting;
	int					live_during_periode;
	
}						t_process

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
