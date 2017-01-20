#include<stdio.h>
#define EXIT_SUCCESS 0

/////////////////////////////////////////////////////////
//						       //
// Program to toogle 2nd bit(from right and left side) //
//						       //
/////////////////////////////////////////////////////////


void printBit(char ch)  //Print the bit of charachter
{
int i;

	for(i = 7 ; i>=0 ; --i)
	{
		ch & (1<<i)?printf("1 "):printf("0 ");
	}

	printf("\n");
}

int main()
{
char ch;

	printf("Enter character.\n");
	scanf("%c",&ch);

	printBit(ch);
	ch = (ch^66);		//Toogle first and last 2nd bit
	printBit(ch);

	return EXIT_SUCCESS;
}
