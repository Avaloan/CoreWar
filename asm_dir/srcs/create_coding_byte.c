/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coding_byte.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 03:42:24 by snedir            #+#    #+#             */
/*   Updated: 2018/04/27 02:38:51 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	get_args_dir(t_env *e, unsigned char *str, int t_off[2], int dir_size)
{
	unsigned int	dir_value;
	int				i;

	dir_value = 0;
	i = 1;
/*	if (e->stock[t_off[1] + i] == ':' && e->stock[t_off[1] + i] != '-')
		get_label;
	else
	{*/
		while (ft_isdigit(e->stock[t_off[1] + i]))
			i++;
		dir_value = ft_atoi(e->stock + t_off[1] + 1);
		if (dir_size == 0)
			number_to_hex(dir_value, str + t_off[0]);
		else
			number_to_hex_size_two(dir_value, str + t_off[0]);
		t_off[0] += i; //tentative decalage de l'index pour str
	//}
}

void	get_args_ind(t_env *e, unsigned char *str, int t_off[2])
{
	unsigned int	ind_value;
	int				i;

	ind_value = 0;
	i = 1;
	/*if (e->stock[t_off[1] + i] == ':' && e->stock[t_off[1] + i] != '-')
		get_label;
	else
	{*/
		while (ft_isdigit(e->stock[t_off[1] + i]))
			i++;
		ind_value = ft_atoi(e->stock + t_off[1] + 1);
		number_to_hex_size_two(ind_value, str + t_off[0]);
		t_off[0] += i; //tentative decalage de l'index pour str
	//}
}

void	get_args_reg(t_env *e, unsigned char *str, int t_off[2])
{
	int				reg_number;
	int				i;

	i = 1;
	reg_number = 0;
	while (ft_isdigit(e->stock[t_off[1] + i]))
		i++;
	reg_number = ft_atoi(e->stock + t_off[1] + 1);
	str[t_off[0]] = (reg_number << 16 & 0xff000000) >> 24 & 0x000000ff;
	t_off[0] += i; //tentative decalage de l'index pour str
}

void	fill_coding_byte(unsigned char *coding_byte, int t[4], int id)
{
	if (id == 0)
	{
		*coding_byte |= REG >> t[3];
		t[3] += 2;
		t[1] = 1;
	}
	if (id == 1)
	{
		*coding_byte |= _DIR >> t[3];
		t[3] += 2;
		t[1] = 1;
	}
	if (id == 2)
	{
		*coding_byte |= IND >> t[3];
		t[3] += 2;
		t[1] = 1;
	}
}

int		create_coding_byte(t_env *e, int start, int t_off[2], int opcode, unsigned char *str)
{
	unsigned char	coding_byte;
	int				t[5];

	t[0] = e->count + start; //offset
	t[1] = 0; //next_separator
	t[2] = 0; //i
	t[3] = 0; //trileen
	coding_byte = 0;
	while (e->stock[t[0] + t[2]] != '\n' &&
			e->stock[t[0] + t[2]] != COMMENT_CHAR)
	{
		if (e->stock[t[0] + t[2]] == 'r' && t[1] == 0)
		{
			fill_coding_byte(&coding_byte, t, 0);
			get_args_reg(e, str, t_off);
		}
		if (e->stock[t[0] + t[2]] == '%' && t[1] == 0)
		{
			fill_coding_byte(&coding_byte, t, 1);
			get_args_dir(e, str, t_off, g_op_tab[opcode].dir_size);
		}
		if ((e->stock[t[0] + t[2]] == '-' || ft_isdigit(e->stock[t[0] + t[2]])
					|| e->stock[t[0] + t[2]] == LABEL_CHAR) && t[1] == 0)
		{
			fill_coding_byte(&coding_byte, t, 2);
			get_args_ind(e, str, t_off);
		}
		if (e->stock[t[0] + t[2]] == ',' && t[1])
			t[1] = 0;
		t[2] += 1;
	}
	return (coding_byte);
}

void	menu_args_coding_byte(t_env *e, int start, int opcode)
{
	unsigned char	*str;
	int				t_off[2];
	unsigned char	coding_byte;
	int				i;

	str = NULL;
	t_off[0] = 0;//index = 0;
	t_off[1] = e->count + start; //offset
	i = -1;
	if (!(str = ft_memalloc(20)))
		ft_perror("");
	coding_byte = create_coding_byte(e, start, t_off, opcode, str);
	add_command(e, &coding_byte, 1);
	while (str[++i])
		;
	add_command(e, str, i);
	free(str);
}
