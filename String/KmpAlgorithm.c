#include<stdio.h>
#include<stdlib.h>
#define null NULL

int my_strlen(char *str)		//To get length of string
{
int i;

	for(i = 0 ; str[i] ;++i);

	return i;
}

void buildArray(int *a,int size,char *str)	//this function will build integr array to look back in pattern
{
int i=1,j=0;
	
	a[0] = 0;	

	while(str[i])
	{
		if(str[i] == str[j])
		{
			a[i] = a[j]+1;
			++i,++j;
		}

		else
		{
			if(j == 0)
			{
				a[i] = 0;
				++i;
			}

			else
			{
				j = a[j-1];
			}
		}
	}
}

void kmpSearch(char *mainString,char *pattern)
{
int mainLen = my_strlen(mainString);
int subLen = my_strlen(pattern);
int i = 0 ,j = 0,arr[subLen];

	buildArray(arr,subLen,pattern);

	while(mainString[i])
	{
		if(mainString[i] == pattern[j])
		{
			++i,++j;
		}

		if(j == subLen)
		{
			printf("Pattern found at %d index.\n",i-j);
			j = arr[j-1];
		}

		else if(i < mainLen && mainString[i] != pattern[j])
		{
			if(j!=0)
				j = arr[j-1];

			else
				++i;
		}
	}
}

char* getString(void)
{
char *ret = null,ch;
int i = 0;

	ret = (char*) malloc(sizeof(char));

	while((ch = getc(stdin))!= '\n')
	{
		ret[i] = ch;
		++i;
		ret = (char*) realloc(ret,i+1);
	}

	ret[i] = '\0';

	return ret;
}

int main()
{
char *mainString = null,*subString = null;

	printf("Enter string.\n");
	mainString = getString();

	printf("Enter String to search in main string.\n");
	subString = getString();

	kmpSearch(mainString,subString);


	return EXIT_SUCCESS;
}
