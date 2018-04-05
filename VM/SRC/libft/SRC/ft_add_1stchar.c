/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_1stchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 03:28:01 by gquerre           #+#    #+#             */
/*   Updated: 2017/09/15 03:34:08 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_1stchar(char *str, char c)
{
	char	*add;

	add = NULL;
	add = ft_strnew(1);
	add[0] = c;
	add = ft_strjoin(add, str);
	return (add);
}
