/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_arena.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 02:07:51 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/20 05:50:11 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".h"

int	ft_create_arena(t_env *e)
{
	if (!(e->arena = (ft_memalloc(sizeof(unsigned char) * (MEM_SIZE)))))
		return (0);
	if (!(e->players = (ft_memalloc(sizeof(t_player *) * e->nb_of_pl))))
		return (0);
	if (!(e->pc_list = ft_memalloc(sizeof(t_process *))))
		return (0);
	return (1);
}
