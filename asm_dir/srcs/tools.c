/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 01:27:44 by fdidelot          #+#    #+#             */
/*   Updated: 2018/04/17 23:09:39 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int size_line(char *stock, int count)
{
	int size;

	size = 0;
	while(stock[size + count] != '\n' && stock[size + count] != '\0')
		size++;
	return (size);
}

int skip_space(char *str)
{
	int i;

	i = 0;
	while (!(str[i] > 32 && str[i] < 127))
		i++;
	return (i);
}

int skip_empty_and_com(char *str)
{
	int i;

	i = 0;
	while (str[i] != '.' && !ft_isalpha(str[i]) && !ft_isdigit(str[i]) && str[i] != '_')
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
