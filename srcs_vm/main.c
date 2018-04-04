#include <stdio.h>
#include "../includes/corewar.h"


void	write_nb_bytes(t_env *e, int input, int arg_size)
{
	int i = 0;
	int tmp = 0;

	/*if (arg_size == 1) ?
		e->arena[pc->pos] = (unsigned char)input;
		return;*/
	while (input && i < arg_size)
	{
		tmp = input >> 8 * arg_size - 1;
		e->arena[pc->pos] = tmp;
		input <<= 8 * arg_size - 1;
		i++;
	}
}

int main()
{
	t_env *e;

	e = ft_memalloc(sizeof(t_env));
	e->arena = ft_memalloc(sizeof(unsigned char) * 4096);
	e->pc_list = ft_memalloc(sizeof(t_process));
	e->arena[0] = 4;
	e->arena[1] = 84;
	e->arena[2] = 1;
	e->arena[3] = 0;
	e->arena[4] = 0;
	e->arena[5] = 1;
	e->arena[6] = 255;
	e->arena[7] = 255;
	e->arena[8] = 255;
	e->arena[9] = 255;
	e->arena[10] = 0;
	e->arena[11] = 0;
	e->arena[12] = 0;
	e->arena[13] = 16;
	int i = 0;
	//fonction_lancement_op(e, e->pc_list);
}
