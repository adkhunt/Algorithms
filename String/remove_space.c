#include<stdio.h>
#include<string.h>
#include"string.h"

void RemoveSpace(char *str)
{
int i,j;

	for(i=0;str[i];i++)
	{
		if(str[i]==' '&& str[i+1]==' ')
		{
			for(j=i+1;str[j];j++)
				str[j]=str[j+1];
			i--;
		}
	}
}

int main()
{
char *str = getString();

	printf("String = %s\n",str);

	RemoveSpace(str);

	printf("New String : %s\n",str);

	return EXIT_SUCCESS;
}
