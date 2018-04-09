/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 06:21:41 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/09 06:45:29 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"
#include <unistd.h> 
#include <sys/time.h> 
  
int unix_text_kbhit(void) 
{
	struct timeval tv;
	tv = {0, 0};
	fd_set readfds;
	FD_ZERO(&readfds);
	FD_SET(STDIN_FILENO, &readfds); 
	return (select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv) == 1); 
}

int	ft_keypad(WINDOW *win, boof bf)
{
	int	key_pressed;

	key_pressed = getchr();
	if (key_pressed = 'p')
		while (getchr() != 'p')
		{}
	return (1);
}
