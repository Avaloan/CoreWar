/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 04:02:28 by fdidelot          #+#    #+#             */
/*   Updated: 2018/03/14 06:01:08 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	check_s_ponkt(char *str)
{
	while(*(str++))
		;
	if (*(str - 2) == 's' && *(str - 3) == '.')
		return (1);
	printf("%c\n", *(str - 2));
	return (0);
}

int	main(int ac, char **av)
{
	int	fd;
	int	off_set = 0;
	char	*stock;

	if (ac != 2 || !check_s_ponkt(av[1]))
		ft_perror("Mets un joueur ouech.\n");
	if (!(fd = open(av[1], O_RDONLY)))
		ft_perror("Open() failed.\n");
	printf("fd = %d\n", off_set);
	off_set = lseek(fd, 0, SEEK_END);
	printf("fd = %d", off_set);
	stock = (char *)ft_memalloc(sizeof(char) * off_set);
	lseek(fd, 0, SEEK_SET);
	read(fd, stock, off_set);
	printf("Player :\n%s\n", stock);
	return (0);
}
