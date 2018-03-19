/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 01:04:40 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/19 05:42:34 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".h"

int	ft_import_champ(t_env *e, int i, char *argv)
{
	utiliser lseek pour inserer les valeurs dans la map;
}

int	ft_init_player(t_env *e, int i, char *argv)
{
	e->player[i][NUM_PLAYER] = i;
	e->player[i][ID] = MAX_INT - e->player[i][NUM_PLAYER];
	e->player[i][LIVES_PERIODE] = 0;
	e->player[i][TOTAL_LIVES] = 0;
	e->player[i][LAST_LIVE] = 0;
	if (!ft_import_champ(e, i, argv))
		return (0);
	return (1);
}
