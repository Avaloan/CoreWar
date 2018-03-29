/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 01:04:40 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/29 07:24:57 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

void	ft_fill_magic(unsigned char *magic_nb)
{
	magic_nb[0] = 0;
	magic_nb[1] = 234;
	magic_nb[2] = 131;
	magic_nb[3] = 243;
}

off_t	ft_save_name(t_env *e, int i, int fd)
{
	unsigned char	magic_nb[4];
	unsigned char	*buff;
	int				k;

	ft_fill_magic(magic_nb);
	k = -1;
	if (!(buff = ft_memalloc(sizeof(char) * 4)))
		return (0);
	if ((read(fd, buff, 4)) == -1)
		return (0);
	while (++k < 4)
		if (buff[k] != magic_nb[k])
		{
			free(buff);
			return (0);
		}
	free(buff);
	if (!(e->players[i].name = ft_memalloc(sizeof(char) * (NAME_SIZE))))
		return (0);
	if (read(fd, e->players[i].name, NAME_SIZE) == -1)
		return (0);
	return (140);
}

off_t	ft_save_comment(t_env *e, int i, int fd, off_t pos)
{
	//off_t	size;
	if (lseek(fd, pos, SEEK_SET) == -1)
		return (0);
//	size = prendre_la_taille_indiquee_juste_avant_comment : calcul sur bits;
	if (!(e->players[i].comment = ft_memalloc(sizeof(char) * (COMMENT_SIZE))))
		return (0);
	if (read(fd, e->players[i].comment, COMMENT_SIZE) == -1)
		return (0);
	return (2192);
}

off_t	ft_put_champ_in_arena(t_env *e, int i, int fd, off_t pos)
{
	off_t			end;
	int				place_in_arena;
	unsigned char	*buff;

	place_in_arena = (MEM_SIZE * i / e->nb_of_pl);
	end = 0;
	buff = NULL;
	if (lseek(fd, pos, SEEK_SET) == -1)
		return (0);
	if (!(buff = ft_memalloc(sizeof(char) * (49))))
		return (0);
	if (read(fd, buff, 49) == -1)
		return (0);

	if (ft_strcpy_until_unsigned(&e->arena[place_in_arena], buff, 49) == NULL)
	{
		ft_strdel(&buff);
		return (0);
	}
	ft_strdel(&buff);
	return (1);
}

int	ft_import_champ(t_env *e, int i, char *argv)
{
	int			fd;
	off_t		pos;

	fd = 0;
	pos = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (0);
	if (!(pos = ft_save_name(e, i, fd)))
		return (0);
	if (!(pos = ft_save_comment(e, i, fd, pos)))
		return (0);
	if (!(ft_put_champ_in_arena(e, i, fd, pos)))
		return (0);
	close(fd);
	return (1); 
}

int	ft_init_player(t_env *e, char *argv)
{
	static int	i = 0;

	e->players[i].num_player = i + 1;
	e->players[i].id = INT_MAX - e->players[i].num_player;
	e->players[i].lives_periode = 0;
	e->players[i].total_lives = 0;
	e->players[i].last_live = 0;
	if (!(ft_import_champ(e, i, argv)))
		return (0);
	i++;
	return (1);
}
