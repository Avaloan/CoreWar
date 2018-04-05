/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 02:22:38 by gquerre           #+#    #+#             */
/*   Updated: 2017/04/18 03:17:18 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strclr_until(char *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	*new;

	i = 0;
	j = 0;
	new = NULL;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == c)
	{
		str[i++] = '\0';
		k = i;
		new = malloc(sizeof(char) * ft_strlen(&str[k]));
		while (str[i] != '\0')
		{
			new[j] = str[i];
			j++;
			i++;
		}
		i = 0;
		ft_strclr(str);
	}
	return (new);
}
