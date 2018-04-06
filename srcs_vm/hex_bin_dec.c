#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void printMenu()
{
	printf("\n\033[22;35m					H E X_T O_B I N_T O_D E C\033[0m\n");
	printf("\033[01;34mSelect Your Option :\033[0m\n	0: Valeur Hexa\n	1: Valeur Dec\n	2: Valeur Bin\n");
}

void to_lower(char *str)
{
	for(int i = 0; str[i]; i++){
		str[i] = tolower(str[i]);
	}
}

int search(char num)
{
	int i = 0;
	char str[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', '\0'};
	for (i = 0; str[i] && num != str[i]; i++);
	return (i);
}


unsigned int hexaToDec(char *line)
{
	unsigned int decValue = 0;
	to_lower(line);
	size_t len = strlen(line);
	for (int i = 0; line[i]; i++)
		decValue += pow(search(line[i]), (len - i) - 1);
	printf("decValue = %zd\n", decValue);
	return (decValue);
}

//int hexaTobin

int main()
{
	int choice;
	int stock;

	printMenu();
	char chaine[64];
	for (int i = 0; i < 64; i++)
		chaine[i] = '\0';
	while ((choice=getchar()) != 4)
	{
		switch (choice)
		{
			case 0:
				scanf("%s", chaine);
				hexaToDec(chaine);
				break;
			case 1:
				printf("Valeur Dec\n");
				break;
			case 2:
				printf("Valeur Bin\n");
				break;
			case 3:
				exit(0);
				return (0);
				break;
			default:
				printf("Unvalid\n");
		}
		if (choice == 3)
			break;
	}
}
