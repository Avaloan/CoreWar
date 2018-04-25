/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 01:23:42 by fdidelot          #+#    #+#             */
/*   Updated: 2018/04/24 06:41:58 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	xozf_command(t_env *e, int i, int sl)
{
//	printf("||||||||%d\n", (int)g_op_tab[0].arg_type[0]);
	if (ft_strncmp(e->stock + e->count + i, "xor", 3) == 0 && (e->stock[e->count + i + 3] > 126 || e->stock[e->count + i + 3] < 33))
		printf("xor\n");
//		return (xor_operator(e, i, sl));
	if (ft_strncmp(e->stock + e->count + i, "or", 2) == 0 && (e->stock[e->count + i + 2] > 126 || e->stock[e->count + i + 2] < 33))
		printf("or\n");
//		return (or_operator(e, i, sl));
	if (ft_strncmp(e->stock + e->count + i, "zjmp", 4) == 0 && (e->stock[e->count + i + 4] > 126 || e->stock[e->count + i + 4] < 33))
		printf("zjump\n");
//		return (zjump_operator(e, i, sl));
	if (ft_strncmp(e->stock + e->count + i, "fork", 4) == 0 && (e->stock[e->count + i + 4] > 126 || e->stock[e->count + i + 4] < 33))
		printf("fork\n");
//		return (fork_operator(e, i, sl));
	sl = 0;
	return (1);
}

int	a_command(t_env *e, int i, int sl)
{
	if (ft_strncmp(e->stock + e->count + i, "add", 3) == 0 && (e->stock[e->count + i + 3] > 126 || e->stock[e->count + i + 3] < 33))
		printf("add\n");
//		return (add_operator(e, i, sl));
	if (ft_strncmp(e->stock + e->count + i, "and", 3) == 0 && (e->stock[e->count + i + 3] > 126 || e->stock[e->count + i + 3] < 33))
		printf("and\n");
//		return (and_operator(e, i, sl));
	if (ft_strncmp(e->stock + e->count + i, "aff", 3) == 0 && (e->stock[e->count + i + 3] > 126 || e->stock[e->count + i + 3] < 33))
		printf("aff\n");
//		return (aff_operator(e, i, sl));
	sl = 0;
	return (1);
}

int	s_command(t_env *e, int i, int sl)
{
	if (ft_strncmp(e->stock + e->count + i, "st", 2) == 0 && (e->stock[e->count + i + 2] > 126 || e->stock[e->count + i + 2] < 33))
		printf("st\n");
//		return (st_operator(e, i, sl));
	if (ft_strncmp(e->stock + e->count + i, "sub", 3) == 0 && (e->stock[e->count + i + 3] > 126 || e->stock[e->count + i + 3] < 33))
		printf("sub\n");
//		return (sub_operator(e, i, sl));
	if (ft_strncmp(e->stock + e->count + i, "sti", 3) == 0 && (e->stock[e->count + i + 3] > 126 || e->stock[e->count + i + 3] < 33))
		printf("sti\n");
//		return (sti_operator(e, i, sl));
	sl = 0;
	return (1);
}

int	l_command(t_env *e, int i, int sl)
{
	if (e->stock[e->count + i + 1] == 'd' && (e->stock[e->count + i + 2] > 126 || e->stock[e->count + i + 2] < 33))
		printf("ld\n");
//		return (ld_operator(e, i, sl));
	if (ft_strncmp(e->stock + e->count + i, "live", 4) == 0 && (e->stock[e->count + i + 4] > 126 || e->stock[e->count + i + 4] < 33))
		return (live_operator(e, i + 4, sl));
	if (ft_strncmp(e->stock + e->count + i, "ldi", 3) == 0 && (e->stock[e->count + i + 3] > 126 || e->stock[e->count + i + 3] < 33))
		printf("ldi\n");
//		return (ldi_operator(e, i, sl));
	if (ft_strncmp(e->stock + e->count + i, "lld", 3) == 0 && (e->stock[e->count + i + 3] > 126 || e->stock[e->count + i + 3] < 33))
		printf("lld\n");
//		return (lld_operator(e, i, sl));
	if (ft_strncmp(e->stock + e->count + i, "lldi", 4) == 0 && (e->stock[e->count + i + 4] > 126 || e->stock[e->count + i + 4] < 33))
		printf("lldi\n");
//		return (lldi_operator(e, i, sl));
	if (ft_strncmp(e->stock + e->count + i, "lfork", 5) == 0  && (e->stock[e->count + i + 5] > 126 || e->stock[e->count + i + 5] < 33))
		printf("lfork\n");
//		return (lfork_operator(e, i, sl));
	sl = 0;
	return (1);
}

int	valid_command(t_env *e, int sl)
{
	int	i;

	i = skip_label(e, sl);
//	printf("stock without label [%s]\n", e->stock + e->count + i);
	i += skip_space(e->stock + e->count + i);
	if (i < sl)
	{
		if (e->stock[e->count + i] == 'l')
			return(l_command(e, i, sl));
		else if (e->stock[e->count + i] == 's')
			return(s_command(e, i, sl));
		else if (e->stock[e->count + i] == 'a')
			return(a_command(e, i, sl));
		else if (e->stock[e->count + i] == 'o')
			return(xozf_command(e, i, sl));
		else if (e->stock[e->count + i] == 'x')
			return(xozf_command(e, i, sl));
		else if (e->stock[e->count + i] == 'z')
			return(xozf_command(e, i, sl));
		else if (e->stock[e->count + i] == 'f')
			return(xozf_command(e, i, sl));
		else
			return (0);
	}
	return (1);
}
/*

	while (i < sl)
	{
		if (!(e->stock[e->count + i] < 33 || e->stock[e->count + i] > 126))
			if (!analyse_command(e, i, sl))
				return (0);
	}
*/
