#include <stdio.h>
#include "../includes/corewar.h"

int main()
{
	t_env *e;

	e = ft_memalloc(sizeof(t_env));
	e->arena = ft_memalloc(sizeof(unsigned char) * 4096);
	e->pc_list = ft_memalloc(sizeof(t_process));
	e->arena[0] = 2;
	e->arena[1] = 144;
	e->arena[2] = 0;
	e->arena[3] = 0;
	e->arena[4] = 0;
	e->arena[5] = 5;
	e->arena[6] = 45;
	e->arena[7] = 1;
	e->arena[8] = 255;
	e->arena[9] = 255;
	int i = 0;
	fonction_lancement_op(e, e->pc_list);
}
