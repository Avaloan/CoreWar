/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 04:36:59 by snedir            #+#    #+#             */
/*   Updated: 2018/03/14 05:56:56 by snedir           ###   ########.fr       */
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
	s_process				*next;
}							t_process;

typedef struct				s_players
{


typedef struct				s_env
{
	int						nbr_of_players;
	void					*(op_code)(s_env *,int,int,int);
	t_process				*pc_list;
	void					*arena;
}							t_env;

#endif
