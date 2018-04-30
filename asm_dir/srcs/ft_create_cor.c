/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 02:10:52 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/30 05:13:07 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	ft_put_in(int fd, char *input, int max_size)
{
	int	i;

	i = 0;
	if ((i = ft_strlen(input)) == 0)
		return (-1);
	write(fd, input, i);
	return (max_size - i);
}

int	ft_create_cor(t_env *e)
{
	int				fd;
	int				i;
	int				empty;
	unsigned char	tmp[2];
	unsigned char	lol[4];

	empty = 0;
	if ((fd = open(e->name_file, O_CREAT | O_WRONLY, 0777)) == -1)
		return (-1);
	number_to_hex(MAGIC_NUMBER, lol);
	write(fd, lol, 4);
	if ((empty = ft_put_in(fd, e->name_player, PROG_NAME_LENGTH)) < 0)
		return (0);
	i = -1;
	while (++i < empty + 6)
		write(fd, "\0", 1);
	number_to_hex_size_two(e->size_player, tmp);
	write(fd, tmp, 2);
	if ((empty = ft_put_in(fd, e->comment, COMMENT_LENGTH)) < 0)
		return (0);
	i = -1;
	while (++i < empty + 4)
		write(fd, "\0", 1);
	write(fd, e->player_buff, e->size_player);
	close(fd);
	return (1);
}
