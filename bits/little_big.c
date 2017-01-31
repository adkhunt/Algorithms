#include<stdio.h>

////////////////////////////////////////////
//					  //
// Program to convert litte endian to big //
// endian				  //
//					  //
////////////////////////////////////////////

void printBinary(int num)
{
int i;

	for(i = 31 ; i  >= 0 ; --i)
	{
		printf("%d",(num>>i)&1);
		if(i%8 == 0)
			printf(" ");
	}

	printf("\n");
}

int main()
{
int x;

	printf("Enter number.\n");
	scanf("%d",&x);

	printBinary(x);
	x = ( x >> 24 ) | (( x << 8) & 0x00ff0000 )| ((x >> 8) & 0x0000ff00) | ( x << 24)  ;
	printBinary(x);

	return 0;
}
