#include<stdio.h>
#include<stdlib.h>
#include"string.h"
#define exit_success EXIT_SUCCESS
#define null NULL

void commonCharacters(char *str,char *str2)
{
int hash[256] = {0};
int i;

	for(i = 0 ; str[i] ; ++i)
		hash[str[i]] = 1;

	for(i = 0 ; str2[i] ; ++i)
	{
		if(hash[str2[i]])
		{
			printf("%c ",str2[i]);
			hash[str2[i]] = 0;
		}
	}

	printf("\n");
}

int main()
{
char *str = getString();
char *str2 = getString();

	printf("String 1 = %s\n",str);
	printf("Stirng 2 = %s\n",str2);

	commonCharacters(str,str2);

	return exit_success;
}
