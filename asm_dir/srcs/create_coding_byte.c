/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coding_byte.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 03:42:24 by snedir            #+#    #+#             */
/*   Updated: 2018/04/27 05:28:19 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	get_args_dir(t_env *e, unsigned char *str, int t_off[4], int dir_size)
{
	unsigned int	dir_value;
	int				i;

	dir_value = 0;
	i = 1;
/*	if (e->stock[t_off[1] + i] == ':' && e->stock[t_off[1] + i] != '-')
		get_label;
	else
	{*/printf("le char %c\n", e->stock[t_off[1] + i]);
		printf("%d\n", t_off[0]);
		while (ft_isdigit(e->stock[t_off[1] + i]))
			i++;
		dir_value = ft_atoi(e->stock + t_off[1] + 1);
		printf("euuuuh dir value %d\n", dir_value);
		if (dir_size == 0)
			number_to_hex(dir_value, str + t_off[0]);
		else
			number_to_hex_size_two(dir_value, str + t_off[0]);
		for (int zz = 0 ; zz < 20 ; zz++)
			printf("%.2x\n", str[zz]);
		t_off[0] += i; //tentative decalage de l'index pour str
	//}
}

void	get_args_ind(t_env *e, unsigned char *str, int t_off[4])
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

void	get_args_reg(t_env *e, unsigned char *str, int t_off[4])
{
	int				reg_number;
	int				i;

	i = 1;
	reg_number = 0;
	printf("%c\n", e->stock[t_off[1] + i]);
	while (ft_isdigit(e->stock[t_off[1] + i]))
		i++;
	reg_number = ft_atoi(e->stock + t_off[1] + 1);
	printf("le reg %d et i %d\n", reg_number, i);
	str[t_off[0]] = ((reg_number << 24 & 0xff000000) >> 24 & 0x000000ff);
	printf("offset b4 %d i = %d\n", t_off[0], i);
	t_off[0] += i; //tentative decalage de l'index pour str
	printf("offset %d\n", t_off[0]);
}

void	fill_coding_byte(unsigned char *coding_byte, int t_off[4], int id)
{
	if (id == 0)
	{
		*coding_byte |= REG >> t_off[2];
		t_off[2] += 2;
		t_off[3] = 1;
	}
	if (id == 1)
	{
		*coding_byte |= _DIR >> t_off[2];
		t_off[2] += 2;
		t_off[3] = 1;
	}
	if (id == 2)
	{
		*coding_byte |= IND >> t_off[2];
		t_off[2] += 2;
		t_off[3] = 1;
	}
}

int		create_coding_byte(t_env *e, int t_off[4], int opcode, unsigned char *str)
{
	unsigned char	coding_byte;

	t_off[2] = 0; //trileen
	t_off[3] = 0; //next_separator
	coding_byte = 0;
	while (e->stock[t_off[1]] != '\n' && e->stock[t_off[1]] != COMMENT_CHAR)
	{
		if (e->stock[t_off[1]] == 'r' && t_off[3] == 0)
		{
			fill_coding_byte(&coding_byte, t_off, 0);
			get_args_reg(e, str, t_off);
		}
		if (e->stock[t_off[1]] == '%' && t_off[3] == 0)
		{
			fill_coding_byte(&coding_byte, t_off, 1);
			get_args_dir(e, str, t_off, g_op_tab[opcode].dir_size);
		}
		if ((e->stock[t_off[1]] == '-' || ft_isdigit(e->stock[t_off[1]])
					|| e->stock[t_off[0]] == LABEL_CHAR) && t_off[3] == 0)
		{
			fill_coding_byte(&coding_byte, t_off, 2);
			get_args_ind(e, str, t_off);
		}
		if (e->stock[t_off[1]] == ',' && t_off[3])
		{
			t_off[3] = 0;
			printf("\n");
		}
		t_off[1] += 1;
	}
	return (coding_byte);
}

void	menu_args_coding_byte(t_env *e, int start, int opcode)
{
	unsigned char	*str;
	int				t_off[5];
	unsigned char	coding_byte;
	int				i;

	str = NULL;
	t_off[0] = 0;//index = 0;
	t_off[1] = e->count + start; //offset
	i = -1;
	if (!(str = ft_memalloc(20)))
		ft_perror("");
	coding_byte = create_coding_byte(e, t_off, opcode, str);
	printf("Coding_byte = %.2x\n", coding_byte);
	add_command(e, &coding_byte, 1);
	for (int z = 0 ; z < e->size_player ; z++)
		printf("%.2x\n", e->player_buff[z]);
	while (str[++i])
		printf("str = %2.x\n", str[i]);
	add_command(e, str, i);
	free(str);
}
