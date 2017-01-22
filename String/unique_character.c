#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"string.h"

void uniqueCharacter(char *str,char*str1)
{
int table[256] = {0};
int i = 0;

	while(str[i])
	{
		++table[str[i]];
		++i;
	}

	i = 0;

	while(str1[i])
	{
		++table[str1[i]];
		++i;
	}

	i = 0;

	while(i<256)
	{
		if(table[i] == 1)
			printf("%c ",i);

		++i;
	}

	printf("\n");
}

int main()
{
char *str = getString();
char *str2 = getString();

	printf("String 1 = %s\n",str);
	printf("String 2 = %s\n",str2);

	uniqueCharacter(str,str2);

	return EXIT_SUCCESS;
}
