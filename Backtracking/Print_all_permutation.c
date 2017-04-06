#include<stdio.h>

/*
 * Program to print all the possible
 * permutaion of the string which is passed
 * by user
 */

/*
 * Function to count the length of 
 * the string
 */

int my_strlen(char *str)
{
int i;

	for(i = 0 ; str[i] ; ++i);

	return i;
}

/*
 * Swap the two character from their references
 */

void swap(char *a,char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

/*
 * This is the main function which handle
 * the main task which we are going to perform
 */

void print_permutation(char *str,int start,int end)
{
	if(start == end)
	{
		printf("%s\n",str);
		return;
	}


int i;

	for(i = start ; i <= end ; ++i)
	{
		swap(str+i,str+start);
		print_permutation(str,start+1,end);
		swap(str+i,str+start);
	}
}

int main()
{
char str[50];

	printf("Enter string to print all permutation.\n");
	scanf("%s",str);

int len = my_strlen(str);

	print_permutation(str,0,len-1);

	return 0;
}
