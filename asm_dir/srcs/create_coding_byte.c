/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coding_byte.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 03:42:24 by snedir            #+#    #+#             */
/*   Updated: 2018/04/26 23:11:56 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	fill_coding_byte(unsigned char *coding_byte, int *trileen,
		int id, int *next_separator)
{
	if (id == 0)
	{
		*coding_byte |= REG >> *trileen;
		*trileen += 2;
		*next_separator = 1;
	}
	if (id == 1)
	{
		*coding_byte |= _DIR >> *trileen;
		*trileen += 2;
		*next_separator = 1;
	}
	if (id == 2)
	{
		*coding_byte |= IND >> *trileen;
		*trileen += 2;
		*next_separator = 1;
	}
}

int		create_coding_byte(t_env *e, int start, int sl)
{
	unsigned char	coding_byte;
	int				next_separator;
	int				i;
	int				trileen;
	int				offset;

	coding_byte = 0;
	next_separator = 0;
	i = 0;
	trileen = 0;
	offset = e->count + start;
	while (e->stock[offset + i] != '\n' && e->stock[offset + i] != COMMENT_CHAR)
	{
		if (e->stock[offset + i] == 'r' && next_separator == 0)
			fill_coding_byte(&coding_byte, &trileen, 0, &next_separator);
		if (e->stock[offset + i] == '%' && next_separator == 0)
			fill_coding_byte(&coding_byte, &trileen, 1, &next_separator);
		if ((e->stock[offset + i] == '-' || ft_isdigit(e->stock[offset + i])
					|| e->stock[offset + i] == LABEL_CHAR)
				&& next_separator == 0)
			fill_coding_byte(&coding_byte, &trileen, 2, &next_separator);
		if (e->stock[offset + i] == ',' && next_separator)
			next_separator = 0;
		i++;
	}
	return (coding_byte);
}
