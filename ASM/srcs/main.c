/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 04:02:28 by fdidelot          #+#    #+#             */
/*   Updated: 2018/04/30 05:09:40 by snedir           ###   ########.fr       */
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

int	check_command(t_env *e)
{
	int	sl;

	while (e->count != e->off_set)
	{
//	printf("of = %d\n", e->off_set);
//	printf("count = %d\n", e->count);
		sl = size_line(e->stock, e->count);
//	printf("of = %d\n", e->off_set);
//	printf("count = %d\n", e->count);
		if (!(check_line(e, sl)))
			return (0);
		e->count += sl + 1;
	}
	return (1);
}

int	valid_player(t_env *e)
{
	e->count += skip_empty_and_com(e->stock);
	if (!name(e) && !comment(e))
		return (0);
	e->count += skip_empty_and_com(e->stock + e->count);
	if (e->comment_ok)
	{
		if (!name(e))
			return (0);
	}
	else if (e->name_ok)
	{
		if (!comment(e))
			return (0);
	}
	else
		return (0);
	e->count += skip_empty_and_com(e->stock + e->count);
//	printf("%s\n", e->stock + e->count);
	if (!check_command(e))
		return (0);
	return (1);
}

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
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;
	t_env	*e;
 
	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))))
		ft_perror("malloc() failed.\n");
	if (ac != 2 || !check_s_ponkt(av[1], e))
		ft_perror("Invalid file, usage : ./asm *player*.s \n");
	if (!(fd = open(av[1], O_RDONLY)))
		ft_perror("Open() failed.\n");
	e->off_set = lseek(fd, 0, SEEK_END);
	if(!(e->stock = (char *)ft_memalloc(sizeof(char) * e->off_set)))
		ft_perror("malloc() failed.\n");
	lseek(fd, 0, SEEK_SET);
	read(fd, e->stock, e->off_set);
	close(fd);
	if (!valid_player(e))
		ft_perror("Invalid player, i smell some bullshit.\n");
	if (!replace_label(e))
		ft_perror("Invalid label call nigga.\n");
	while (e->lst_label)
	{
		printf("Label = %s\n", e->lst_label->name);
		printf("Placement = %d\n", e->lst_label->placement);
		e->lst_label = e->lst_label->next;
	}
	while (e->stock_label)
	{
		printf(" MegaLabel = %s\n", e->stock_label->name);
		printf("Placement = %d\n", e->stock_label->placement);
		e->stock_label = e->stock_label->next;
	}
	printf("Size = %d\n",e->size_player);
	int i = 0;
	while (i < e->size_player)
	{
		if (i % 8 == 0)
			printf("  ");
		if (i % 16 == 0)
			printf("\n");
		printf("%.2x ", e->player_buff[i]);
		i++;
	}
	printf("\n");
	ft_create_cor(e);
//	if (!create_binary_player(stock, e))
//		ft_perror("I'm too bad for this player, pls call another developer.\n");
//	fd = open(e->name_file, O_CREAT | O_WRONLY, 0777);
//	write(fd, player_buff, size_buff);
//	close(fd);
	return (0);
}


/*

champ_max_size avec commentaires ? nom ? apres calcul du poid ?

*/
