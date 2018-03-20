/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_how_many_pl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 04:31:29 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/20 01:58:08 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".h"

int	ft_how_many_pl(t_env *e, int *argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
		if (argv[i][0] != '\0' && argv[i][0] != '-')
			e->nb_of_pl++;
	if (e->nb_of_pl == 0 || e->nb_of_pl > MAX_PLAYERS)
		return (0);
	return (1);
}
