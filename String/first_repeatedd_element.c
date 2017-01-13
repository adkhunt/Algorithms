#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define null NULL

char* getString()
{
char *ret = null,ch;
int i = 0;

	ret = (char*) malloc(sizeof(char));

	while((ch = getc(stdin))!= '\n')
	{
		ret[i] = ch;
		++i;
		ret = (char*) realloc(ret,sizeof(char)*(i+1));
	}

	ret[i] = '\0';

	return ret;
}

void findFirstRepeated(char *str)
{
bool temp[26] = {false};
int i;

	for(i = 0 ; str[i] ; ++i)
	{
		if(temp[str[i]-97] == false)
			temp[str[i]-97] = true;

		else
		{
			printf("'%c' is first repeated character.\n",str[i]);
			return;
		}
	}
}

int main()
{
char *str = null; 
int i = 0;

	str = getString();
	
	findFirstRepeated(str);
	free(str);

	return EXIT_SUCCESS;
}
