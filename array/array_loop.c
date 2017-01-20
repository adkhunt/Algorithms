#include<stdio.h>
#include<stdlib.h>

void isCycle(int *arr,int n)
{
int count = 0,i;

	while(count<n && i >= 0 && i < n)
	{
			if(arr[i]%n == 0)
			{
				printf("No cycle found.\n");
				return;
			}

			else if(arr[i]>0)
				i = (i+arr[i])%n;

			else
				i = (i-arr[i])%n;

		++count;
	}

	if(i >= 0)
	printf("Cycle is found in array.\n");

	else
		printf("No cycle found.\n");
}

int main()
{
int size,*arr = NULL,i;

	printf("Enter size of array.\n");
	scanf("%d",&size);

	arr = (int*) malloc(sizeof(int)*size);

	for(i = 0 ;i < size ; ++i)
		scanf("%d",&arr[i]);

	isCycle(arr,size);

	return EXIT_SUCCESS;
}
