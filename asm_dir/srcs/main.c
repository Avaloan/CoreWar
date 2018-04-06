/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 04:02:28 by fdidelot          #+#    #+#             */
/*   Updated: 2018/03/24 04:16:28 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_op    g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
	 "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
	 "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
	 "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
	 "load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
	 "store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
	 "long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

int	check_s_ponkt(char *str, t_env *e)
{
	int	i;
	int j;
	int	k;

	i = 0;
	k = 0;
	while (str[i++])
		;
	j = i;
	if (str[i - 3] == '/' || str[i - 2] != 's' || str[i - 3] != '.')
		return (0);
	while (str[i] != '/')
		i--;
	if(!(e->name_file = (char *)ft_memalloc(sizeof(char) * (j - i + 1))))
		ft_perror("malloc() failed.\n");
	while (++i < j + 1)
	{
		if (i < j - 2)
			e->name_file[k] = str[i];
		else if (i == j - 2)
			e->name_file[k] = 'c';
		else if (i == j - 1)
			e->name_file[k] = 'o';
		else if (i == j)
			e->name_file[k] = 'r';
		k++;
	}
	e->name_file[k] = '\0';
	printf("%s\n",e->name_file);
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;
	t_env	*e;

	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))))
		ft_perror("malloc() failed.\n");
	if (ac != 2 || !check_s_ponkt(av[1], e))
		ft_perror("Mets un joueur ouech.\n");
	if (!(fd = open(av[1], O_RDONLY)))
		ft_perror("Open() failed.\n");
	e->off_set = lseek(fd, 0, SEEK_END);
	if (e->off_set > CHAMP_MAX_SIZE)
		ft_perror("Champ too fat, go on a diet.\n");
	if(!(e->stock = (char *)ft_memalloc(sizeof(char) * e->off_set)))
		ft_perror("malloc() failed.\n");
	lseek(fd, 0, SEEK_SET);
	read(fd, e->stock, e->off_set);
	close(fd);
	fd = open(e->name_file, O_CREAT | O_WRONLY, 0777);
	return (0);
}

/*

retour du lseek ???


*/
