/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 01:20:17 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/29 07:27:41 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar_vm.h"

int	main(int argc, char **argv)
{
//	int	u;
//	int	v;
	int		i;
	t_env	*e;

	i = 0;
	printf("1\n");
	if (!(e = ft_memalloc(sizeof(t_env))) || ft_create_arena(e) == 0)
		return (ft_error(e, 1));
	printf("2\n");
	if (ft_how_many_pl(e, argc, argv) == 0)
		return (ft_error(e, 2));
	printf("3\n");
	while (++i < argc)
	{
		printf("4\n");
		if (e->option > 0)
			if (ft_apply_option(e, argv[i], i) == 0)
				return (ft_error(e, 1));
		printf("5\n");
		if (argv[i] && argv[i][0] == '-')
		{
			printf("55\n");
			if (ft_options(e, argv[i]) == 0)
				return (ft_error(e, 3));
			printf("6\n");
		}
		else if (ft_init_player(e, argv[i]) == 0)
		{
			printf("555\n");
			return (ft_error(e, 4));
		}
		printf("7\n");
	}
	printf("8\n");
	if (ft_init_process(e) == 0)
		return (ft_error(e, 5));
	printf("9\n");
/*	u = 0;
	while (u < 64)
	{
		v = 0;
		while (v < 64)
		{
			printf(" ");
			printf("%.2x", e->arena[u * 64 + v]);
			v++;
		}
		u++;
	}*/
	if (ft_game_runner(e) == 0)
		return (ft_error(e, 6));
	printf("10\n");
	if (ft_finish(e) == 0)
		return (ft_error(e, 7));
	printf("11\n");
	return (0);
}
