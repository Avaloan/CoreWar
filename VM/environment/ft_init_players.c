/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 01:04:40 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/24 05:55:47 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_save_name(t_env *e, int i, int fd)
{
	int		start;
	int		end;
	int		next_one;

	start = 0;
	end = 0;
	next_one = 0;
	if ((end = lseek(fd, 4, SEEK_HOLE) == -1))
		return (0);
	if ((start = lseek(fd, 5, SEEK_SET) == -1))
		return (0);
	if (!(e->player[i]->name = ft_memalloc(sizeof(char) * (end - start))))
		return (0);
	read(fd, e->player[i]->name, end - start);
	if ((next_one = lseek(fd, 4, SEEK_DATA) == -1))
		return (0);
	return (next_one);
}

int	ft_save_comment(t_env *e, int i, int fd, int pos)
{
	int		start;
	int		end;
	int		next_one;

	start = 0;
	end = 0;
	next_one = 0;
	if ((end = lseek(fd, 4, SEEK_HOLE) == -1))
		return (0);
	if ((start = lseek(fd, pos, SEEK_SET) == -1))
		return (0);
	if (!(e->player[i]->comment = ft_memalloc(sizeof(char) * (end - start))))
		return (0);
	read(fd, e->player[i]->comment, end - start);
	if ((next_one = lseek(fd, 4, SEEK_DATA) == -1))
		return (0);
	return (next_one);
}

int	ft_put_champ_in_arena(t_env *e, int i, int fd, int pos)
{
	int		start;
	int		end;
	int		place_in_arena;
	char	*buff;

	place_in_arena = (MEM_SIZE * i / e->nb_of_pl);
	start = 0;
	end = 0;
	buff = NULL;
	if ((end = lseek(fd, 0, SEEK_END) == -1))
		return (0);
	if ((start = lseek(fd, pos, SEEK_SET) == -1))
		return (0);
	if (!(buff = ft_memalloc(sizeof(char) * (end - start))))
		return (0);
	read(fd, buff, end - start);
	if (!(ft_strcpy(e->&arena[place_in_arena], buff)))
	{
		ft_strdel(buff);
		return (0);
	}
	ft_strdel(buff);
	return (1);
}

int	ft_import_champ(t_env *e, int i, char *argv)
{
	int		fd;
	int		pos;

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
	return (1); 
}

int	ft_init_player(t_env *e, char *argv)
{
	static int	i = 0;

	e->player[i]->num_player = i;
	e->player[i]->id = MAX_INT - e->player[i]->num_player;
	e->player[i]->lives_periode = 0;
	e->player[i]->total_lives = 0;
	e->player[i]->last_live = 0;
	if (!(ft_import_champ(e, i, argv)))
		return (0);
	i++;
	return (1);
}
