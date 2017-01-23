#include"header.h"

////////////////////////////////////////////
//					  //
// Program to find the ways to reach at n //
// Step in stair 			  //
//					  //
////////////////////////////////////////////

int getWays(int n)
{
	if(n <= 1)
		return n;

	return getWays(n-1) + getWays(n-2);
}

int main()
{
int steps;

	printf("Enter number of steps.\n");
	scanf("%d",&steps);

	int res = getWays(steps+1);

	printf("%d ways are there.\n",res);

	return EXIT_SUCCESS;
}
