/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 01:20:17 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/20 05:48:10 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".h"

int	main(int *argc, char **argv)
{
	int		i;
	t_env	*e;

	i = -1;
	if (!(e = ft_memalloc(sizeof(t_env *)))) 
		return (ft_error(1));
	if (ft_how_many_pl(e, argc, argv) == 0 || ft_create_arena(e) == 0)
		return (ft_error(1));
	while (++i < argc)
	{
		if (argv[i][0] == '-')
			if (ft_options(e, argv[i] == 0))
				return (ft_error(1));//message erreur : une option a posee probleme
		else if (ft_init_player(e, argv[i]) == 0)
			return (ft_error(1));//message erreur : l'un des joueurs n'a pas ete enregistre
	}
	if (ft_init_env (e) == 0)	//===> init_process + init_checks
		return (ft_error(1));//message erreur : l'initialisation de l'environnement a echoue
	if (ft_treat(e) == 0)		//===> boucle until cycle_to_die contenant boucle cycle < cycle_to_die
		return (ft_error(1));//message erreur : le traitement a echoue
	if (ft_finish(e) == 0)
		return (ft_error(1));//message erreur : la finition pose pb
	return (0);
}
