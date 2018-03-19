/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 04:01:26 by fdidelot          #+#    #+#             */
/*   Updated: 2018/03/19 05:53:13 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/libft.h"

# define MEM_SIZE			(4 * 1024)
# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTHi	(2048)
# define CHAMP_MAX_SIZE		(MEM_SIZE / 6)
# define COMMENT_CHAR		'#'
# define LABEL_CHAR			':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','
# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"
# define REG_NUMBER			16
# define MAX_ARG_TYPE		3
# define T_REG				1
# define T_DIR				2
# define T_IND				4

typedef	char	t_arg_type;

typedef struct	s_op
{
	char		*name;
	int			nb_param;
	t_arg_type	arg_type[MAX_ARG_TYPE];
	int			opcode;
	int			nb_cycle;
	char		*comment;
	int			octal;
	int			dir_size;
}				t_op;

#endif
