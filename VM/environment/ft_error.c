/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 05:46:54 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/24 05:55:18 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_error(int i);
{
	if (i == 1)
		printf("Error.\nMalloc of environment\n");
	else if (i == 2)
		printf("Error.\nWrong number of players\n");
	else if (i == 3)
		printf("Error.\nWrong options\n");
	else if (i == 4)
		printf("Error.\nChampions read failed\n");
	else if (i == 5)
		printf("Error.\nA process initialization failed\n");
	else if (i == 6)
		printf("Error.\nRunning Crashed\n");
	else if (i == 7)
		printf("Error.\nFinishing function failed\n");
	return (1);
}
