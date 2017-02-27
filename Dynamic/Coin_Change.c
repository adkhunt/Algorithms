#include<stdio.h>
#define EXIT_SUCCESS 0
#define INT_MAX 1<<30

////////////////////////////////////////////////////
//						  //
// Program to find the minimum coin required from //
// Given denomination of coins to get total	  //
//						  //
////////////////////////////////////////////////////

int min(int a,int b)
{
	return a < b ? a : b;
}

int get_total_coin(int size,int coin_array[size],int total)
{
int i,temp[total+1],j;

	temp[0] = 0;

	for(i = 1 ; i <= total ; ++i)
		temp[i] = INT_MAX;

	for(i = 0 ; i < size ; ++i)
	{
		for(j = coin_array[i] ; j <= total ; ++j)
		{
			if(coin_array[i] <= j)
			{
				temp[j] = min(temp[j],temp[j-coin_array[i]]+1);
			}
		}
	}

	return temp[total];
}

int main()
{
int coin_array[] = {1,2,5,10};
int total;

	printf("Enter total sum to get required coin.\n");
	scanf("%d",&total);

	int res = get_total_coin(4,coin_array,total);

	printf("Total required coin = %d\n",res);

	return EXIT_SUCCESS;
}
