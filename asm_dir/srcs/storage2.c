/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 04:07:34 by fdidelot          #+#    #+#             */
/*   Updated: 2018/05/02 04:18:14 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	skip_space(char *str)
{
	int i;

	i = 0;
	while (str[i] && !(str[i] > 32 && str[i] < 127))
		i++;
	return (i);
}

int	skip_empty_and_com(char *str)
{
	int i;

	i = 0;
	while (str[i] != '.' && !ft_isalpha(str[i]) &&
		!ft_isdigit(str[i]) && str[i] != '_')
	{
		if (str[i] == '#')
		{
			while (str[i] != '\n')
				i++;
		}
		i++;
	}
	return (i);
}
