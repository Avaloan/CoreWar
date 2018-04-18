/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 02:42:03 by fdidelot          #+#    #+#             */
/*   Updated: 2018/04/18 05:11:46 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	create_label_lst(t_env *e, int start, int end)
{
	t_label *tmp;

	if (e->lst_label == NULL)
	{
		if (!(e->lst_label = (t_label *)ft_memalloc(sizeof(t_label))))
			ft_perror("malloc() failed.\n");
		tmp = e->lst_label;
	}
	else
	{
		tmp = e->lst_label;
		while (tmp->next)
			tmp = tmp->next;
		if (tmp->next == NULL)
		{
			if (!(tmp->next = (t_label *)ft_memalloc(sizeof(t_label))))
				ft_perror("malloc() failed.\n");
			tmp = tmp->next;
		}
	}
	tmp->placement = e->size_player;
	if (!(tmp->name = (char *)ft_memalloc(sizeof(char) * (end - start))))
		ft_perror("malloc() failed.\n");
	ft_strncpy(tmp->name, e->stock + e->count + start, end - start + 1);
	tmp->next = NULL;
}
