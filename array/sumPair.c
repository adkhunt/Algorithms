#include"header.h"
#include<limits.h>
#include<stdbool.h>

//////////////////////////////////////////////////
//						//
// Program to find the pair of sum in O(n) time //
// Complexity in unsorted array			//
//						//
//////////////////////////////////////////////////

void findSum(int *a,int size,int sum)
{
bool hash[1000] = {false};
int i,res;

	for(i = 0 ; i < size ; ++i)
	{
		res = sum - a[i];

		if(hash[res] == true)
		{
			printf("%d + %d = %d\n",res,a[i],sum);
		}

		hash[a[i]] = true;		
	}
}

int main()
{
int *arr = null;
int size,i,sum;

	printf("Enter size of array.\n");
	scanf("%d",&size);

	arr = (int*) malloc(sizeof(int)*size);

	printf("Enter array element.\n");
	for(i = 0 ; i < size ; ++i)
		scanf("%d",&arr[i]);

	printf("Enter sum to find pair.\n");
	scanf("%d",&sum);

	findSum(arr,size,sum);

	return exit;
}
