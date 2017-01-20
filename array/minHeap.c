#include<stdio.h>
#include<stdlib.h>
#define null NULL

/////////////////////////////////////
//				   //
// Program to convert into minHeap //
//				   //
/////////////////////////////////////

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insertInHeap(int *a,int index,int num)
{

	while(index > 0)
	{
		int parent = (index - 1)/2;

		if(a[parent] <= num)
		{
			a[index] = num;
			return;
		}

		else
		{
			swap(&a[parent],&a[index]);
		}

		index = parent;
	}

	a[0] = num;
}

int main()
{
int *a = null;
int size,i,num;

	printf("Enter size of array.\n");
	scanf("%d",&size);

	a = (int*) malloc(sizeof(int)*size);

	printf("Enter element in array : ");
	for(i = 0 ; i < size ; ++i)
	{
		scanf("%d",&num);
		insertInHeap(a,i,num);
	}

	printf("Heap Array : ");
	for(i = 0 ; i < size ; ++i)
		printf("%d ",a[i]);
	printf("\n");

	return EXIT_SUCCESS;
}
