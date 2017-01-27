#include<stdio.h>
#define exit 0

//////////////////////////////////////////
//				 	//
// Program to count the set bit of numb //
//					//
//////////////////////////////////////////

void countBit(int num) // Kernighan Algorithm
{
int count = 0;

	while(num)
	{
		num = num & (num-1);
		++count;
	}

	printf("Set Bit = %d\n",count);
}

int countSetBit(int num)
{
int i,count = 0;

	for(i = 31 ; i >= 0 ; --i)
		if(num & (1<<i))
			++count;

	return count;
}

int main()
{
int num;

	printf("Enter number to count set bit.\n");
	scanf("%d",&num);

	int res = countSetBit(num);

	printf("%d is set bit.\n",res);
	countBit(num);

	return exit;
}
