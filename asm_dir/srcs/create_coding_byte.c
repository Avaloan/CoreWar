/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coding_byte.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 03:42:24 by snedir            #+#    #+#             */
/*   Updated: 2018/05/01 07:55:52 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	get_args_dir(t_env *e, unsigned char *str, t_offset *t_off, int dir_size)
{
	unsigned int	dir_value;
	int				i;

	dir_value = 0;
	i = 2;
	if (dir_size == 1)
		i = 0;
//	printf("stock = %c\n", e->stock[t_off->offset]);
//	printf("stock = %c\n", e->stock[t_off->offset + 1]);
	if (e->stock[t_off->offset + 1] == ':' && e->stock[t_off->offset + 1]
			!= '-')
	{
		e->size_player -= 1;
		get_label(e, t_off->offset - e->count + 1, t_off->size_ope + 2 + i, dir_size);
		e->size_player += 1;
		t_off->size_ope += 2 + i;
//		printf("with label %d\n", dir_size);
/*		for (unsigned int seks = 0; seks < t_off->index_str ; seks++)
			printf("%.2x ", str[seks]);
		printf("\n");*/
		t_off->index_str += 2 + i;
	}
	else
	{
		dir_value = ft_atoi(e->stock + t_off->offset + 1);
		if (dir_size == 0)
		{
			number_to_hex(dir_value, str + t_off->index_str);
			t_off->index_str += 4;
			t_off->size_ope += 4;
		}
		else
		{
			number_to_hex_size_two(dir_value, str + t_off->index_str);
			t_off->index_str += 2;
			t_off->size_ope += 2;
		}
	}
}

void	get_args_ind(t_env *e, unsigned char *str, t_offset *t_off)
{
	unsigned int	ind_value;

	ind_value = 0;
	if (e->stock[t_off->offset] == ':' && e->stock[t_off->offset] != '-')
	{
		e->size_player -= 1;
		get_label(e, t_off->offset - e->count, t_off->size_ope + 2, 1);
		e->size_player += 1;
		t_off->size_ope += 2;
		t_off->index_str += 2;
	}
	else
	{
		ind_value = ft_atoi(e->stock + t_off->offset);
		number_to_hex_size_two(ind_value, str + t_off->index_str);
		t_off->index_str += 2;
		t_off->size_ope += 2;
	}
}

void	get_args_reg(t_env *e, unsigned char *str, t_offset *t_off)
{
	int				reg_number;

	reg_number = 0;
	reg_number = ft_atoi(e->stock + t_off->offset + 1);
	str[t_off->index_str] = ((reg_number << 24 & 0xff000000) >> 24 & 0x000000ff);
	t_off->index_str += 1;
//		for (unsigned int seks = 0; seks < t_off->index_str ; seks++)
//			printf("%.2x ", str[seks]);
	t_off->size_ope += 1;
}

void	fill_coding_byte(unsigned char *coding_byte, t_offset *t_off, int id)
{
	if (id == 0)
	{
		*coding_byte |= REG >> t_off->trileen;
		t_off->trileen += 2;
		t_off->next_separator = 1;
	}
	if (id == 1)
	{
		*coding_byte |= _DIR >> t_off->trileen;
		t_off->trileen += 2;
		t_off->next_separator = 1;
	}
	if (id == 2)
	{
		*coding_byte |= IND >> t_off->trileen;
		t_off->trileen += 2;
		t_off->next_separator = 1;
	}
}

int		create_coding_byte(t_env *e, t_offset *t_off, unsigned char opcode,
		unsigned char *str)
{
	unsigned char	coding_byte;

	t_off->trileen = 0;
	t_off->next_separator = 0;
	coding_byte = 0;
	while (e->stock[t_off->offset] != '\n' && e->stock[t_off->offset] != COMMENT_CHAR)
	{
		if (e->stock[t_off->offset] == 'r' && t_off->next_separator == 0)
		{
			fill_coding_byte(&coding_byte, t_off, 0);
			get_args_reg(e, str, t_off);
		}
		if (e->stock[t_off->offset] == '%' && t_off->next_separator == 0)
		{
			fill_coding_byte(&coding_byte, t_off, 1);
			get_args_dir(e, str, t_off, g_op_tab[opcode].dir_size);
		}
		if ((e->stock[t_off->offset] == '-' || ft_isdigit(e->stock[t_off->offset])
					|| e->stock[t_off->offset] == LABEL_CHAR) &&
				t_off->next_separator == 0)
		{
			fill_coding_byte(&coding_byte, t_off, 2);
			get_args_ind(e, str, t_off);
		}
		if (e->stock[t_off->offset] == ',' && t_off->next_separator)
			t_off->next_separator = 0;
		t_off->offset += 1;
	}
	return (coding_byte);
}

void	menu_args_coding_byte(t_env *e, int start, unsigned char opcode)
{
	unsigned char	*str;
	t_offset		t_off;
	unsigned char	coding_byte;

	str = NULL;
	t_off.index_str = 0;
	t_off.offset = e->count + start;
	t_off.size_ope = 0;
	if (!(str = ft_memalloc(20)))
		ft_perror("");
	coding_byte = create_coding_byte(e, &t_off, opcode, str);
	add_command(e, &coding_byte, 1);
	add_command(e, str, t_off.size_ope);
	free(str);
}
