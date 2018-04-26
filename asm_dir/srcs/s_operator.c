/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 03:08:43 by snedir            #+#    #+#             */
/*   Updated: 2018/04/26 03:42:11 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		st_ope(t_env *e, int start, int sl)
{
	start += skip_space(e->stock + e->count + start);
	if (!check_nb_param(e, start, sl, 2) || !valid_param(e, start, 2))
		return (0);
	
}
























sub_ope()

sti_ope()
