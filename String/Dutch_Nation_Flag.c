#include<stdio.h>
#include<stdlib.h>

void swap(char *a,char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void sort_string(char *str,int len)
{
int k = len-1;
int i=0,j=1;

	while(j<=k)
	{
		if(str[j] == 'r')
		{
			swap(&str[i],&str[j]);
			++i;
		}

		else if(str[j] == 'b')
		{
			swap(&str[j],&str[k]);
			--k;
		}

		else
			++j;
	}
}

int main()
{
char *str = NULL,ch;
int i = 0;

	str = (char*) malloc(sizeof(char));

	printf("Enter string contain r g and b characters only.\n");

	while((ch = getc(stdin))!='\n')
	{
		str[i] = ch;
		++i;
		str = (char*) realloc(str,i+1);
	}

	printf("Entered String is = %s\n",str);
	sort_string(str,i);
	printf("Sorted String = %s\n",str);
	free(str);

	return EXIT_SUCCESS;
}
