#include <stdio.h>
#include "../includes/corewar.h"
#include "../asm_dir/includes/asm.h"
#define E e->arena
int main()
{
	t_env *e;

	e = ft_memalloc(sizeof(t_env));
	e->arena = ft_memalloc(sizeof(unsigned char) * 4096);
	e->pc_list = ft_memalloc(sizeof(t_process));
	e->op_tab = ft_memalloc(sizeof(t_op) * 16);
	e->op_tab[2].op = st;
	e->arena[0] = 3;
	e->arena[1] = 112;
	e->arena[2] = 0;
	e->arena[3] = 0;
	e->arena[4] = 0;
	e->arena[5] = 3;
	e->arena[6] = 0;
	e->arena[7] = 0;
	e->arena[8] = 0;
	e->arena[9] = 0;
	e->arena[10] = 0;
	e->arena[11] = 0;
	e->arena[12] = 0;
	e->arena[13] = 0;
	int i = 0;
	fonction_lancement_op(e, e->pc_list);
	while (i < 14)
	{
		if (i == 7)
			printf("\n");
		printf("%.2x ", E[i]);
		i++;
	}
}
