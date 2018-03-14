/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_arena.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 02:07:51 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/14 04:25:57 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".h"

int	ft_init_players(t_env *e, int nb_of_player)
{
	int	i;

	i = 0;
	while (i < nb_of_players)
	{
		ft_init_players(e, i);
		ft_import_champ(e, i);
	}

}

int	ft_create_arena(t_env *e)
{
	if (!(e->arena = (ft_memalloc(sizeof(unsigned char) * (MEM_SIZE)))))
		return (0);
	return (1);
}


