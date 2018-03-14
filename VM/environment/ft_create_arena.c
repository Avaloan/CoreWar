/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_arena.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 02:07:51 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/14 06:13:22 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".h"

int	ft_init_players(t_env *e)
{
	int	i;

	i = 0;
	while (i < e->nb_of_pl)
	{
		ft_init_process(e, i);//creer les cartes d'identite des process initiaux (et les suivants (fork) ?) - 1 process par joueur
		//cartes organisees en liste chainee;
		//-CONTIENT	&&	-Initializaton :
		//PC		 	MEM_SIZE / e->nb_of_pl * (num_player - 1) ;
		//R1			0 - num_player (ex: Player1, 0 - 1 = FFFF);
		//R2-R16		0;

		ft_import_champ(e, i);//ecrire les champions dans la VM
	}

}

int	ft_create_arena(t_env *e)
{
	if (!(e->arena = (ft_memalloc(sizeof(unsigned char) * (MEM_SIZE)))))
		return (0);
	if (!(e->players = (ft_memalloc(sizeof(t_player *) * e->nb_of_pl))))
		return (0);

	return (1);
}


