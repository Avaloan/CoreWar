/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 01:20:17 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/27 06:12:43 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".h"

int	main(int *argc, char **argv)
{
	int		i;
	t_env	*e;

	i = -1;
	if (!(e = ft_memalloc(sizeof(t_env *))) || ft_create_arena(e) == 0)
		return (ft_error(1));
	if (ft_how_many_pl(e, argc, argv) == 0)
		return (ft_error(2));
	while (++i < argc)
	{
		if (e->option > 0)
			if (ft_apply_option(e, argv[i], i) == 0)
				return (ft_error(33));
		if (argv[i][0] == '-')
			if (ft_options(e, argv[i]) == 0)
				return (ft_error(3));
		else if (ft_init_player(e, argv[i]) == 0)
			return (ft_error(4));
	}
	if (ft_init_process(e) == 0)
		return (ft_error(5));
	if (ft_game_runner(e) == 0)
		return (ft_error(6));
	if (ft_finish(e) == 0)
		return (ft_error(7));
	return (0);
}
