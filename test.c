#include <stdio.h>
#include "../CoreWar/asm_dir/includes/asm.h"

int main()
{
	unsigned char code = 0;
	unsigned char reg = 0b01000000;
	unsigned char ind = 0b11000000;
	unsigned char dir = 0b10000000;
	code = code | REG >> 0;
	printf("%x\n", code);
	code = code | REG >> 2;
	printf("%x\n", code);
	code = code | REG >> 4;
	printf("%x\n", code);
}
