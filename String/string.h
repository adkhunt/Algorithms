#ifndef string
#define string

#include<stdlib.h>

#define null NULL

char* getString()
{
char *ptr = null;
char ch;
int i=0;

	ptr = (char *) malloc(sizeof(char)*1);

	while((ch = getc(stdin)) != '\n')
	{
		ptr[i++] = ch;
		ptr = (char*) realloc(ptr,i+1);
	}

	ptr[i] = '\0';

	return ptr;
}

#endif
