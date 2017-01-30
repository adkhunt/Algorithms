#include<stdio.h>
#define exit 0

////////////////////////////////////////////////
//					      //
// Program to reverse the bit of given number //
//					      //
////////////////////////////////////////////////

int reverseBit(int num)
{
int i = 0,j = 31;
int m,n;

	while(i<j)
	{
		m = (num>>i) & 1;
		n = (num>>j) & 1;

		if(m != n)
		{
			num = num ^ (1<<i);
			num = num ^ (1<<j);
		}

		++i,--j;
	}

	return num;
}

void printBinary(int num)
{
int i;

	for(i = 31 ;i >= 0 ; --i)
	{
		printf("%d",(num>>i) & 1);
		if(!(i%8))
			printf(" ");
	}

	printf("\n");
}

int main()
{
int num;

	printf("Enter number in variabl.\n");
	scanf("%d",&num);

	printBinary(num);
	num = reverseBit(num);
	printBinary(num);

	return exit;
}
