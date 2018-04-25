
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 02:38:44 by fdidelot          #+#    #+#             */
/*   Updated: 2018/04/25 06:11:29 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	get_label(t_env *e, int start, unsigned char *command)
{
	
}

void	add_command(t_env *e, unsigned char *command, int size)
{
	int i;

	i = 0;
	if (e->player_buff == NULL)
	{
		if (!(e->player_buff = (char *)ft_memalloc(sizeof(char) * CHAMP_MAX_SIZE)))
			ft_perror("malloc() failed.\n");
	}
	while (i < size)
	{
		e->player_buff[i + e->size_player] = command[i];
		i++;
	}
	if (e->size_player + size > CHAMP_MAX_SIZE)
		ft_perror("Champ too fat, go on a diet.\n");
	e->size_player += size;
	i = 0;
}

void	number_to_hex(unsigned int num, unsigned char *dest)
{
	int i = 0;
	dest[0] = num >> 24 & 0x000000ff;
	dest[1] = (num << 8 & 0xff000000) >> 24 & 0x000000ff;
	dest[2] = (num << 16 & 0xff000000) >> 24 & 0x000000ff;
	dest[3] = (num << 24 & 0xff000000) >> 24 & 0x000000ff;
	while (i < 4)
	{
		printf("num[%d] = %x\n", i, dest[i]);
		i++;
	}
}

int	live_operator(t_env *e, int start, int sl)
{
	int				retatoi;
	int				label;
	unsigned char	*command;

	label = 0;
	start += skip_space(e->stock + e->count + start);
	if (!check_nb_param(e, start, sl, 0) || !valid_param(e, start, 0))
		return (0);
//	printf("live op = %d\n", g_op_tab[0].nb_param);
	start++;
	if (!(command = (unsigned char *)ft_memalloc(sizeof(unsigned char) * 5)))
		ft_perror("malloc() failed.\n");
	command[0] = 0x01;
	if (e->stock[e->count + start] == LABEL_CHAR)
		get_label(e, start, command);
	else
	{
		retatoi = ft_atoi(e->stock + e->count + start);
		number_to_hex(retatoi, command + 1);
	}
	add_command(e, command, 5);
	return (1);
}
