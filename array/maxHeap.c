#include<stdio.h>
#include<stdlib.h>
#define null NULL
#define exit_success EXIT_SUCCESS

//////////////////////////////////////////
//					//
// Program to insert in max heap array //
//					//
//////////////////////////////////////////

void swap(int *a,int *b)		//swap function pass by reference
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insertMaxheap(int *a,int index,int num)	// Heapfy the insertion in array
{

	while(index>0)
	{
		int parent = (index-1)/2;

		if(a[parent] >= num)
		{
			a[index] = num;
			return;
		}

		else
		{
			swap(a+index,a+parent);
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

	a = (int*) malloc(sizeof(int)*size);	// allocate the memory according size

	printf("Enter element in array. : ");

	for(i = 0 ; i < size ; ++i)
	{
		scanf("%d",&num);
		insertMaxheap(a,i,num);
	}

	printf("Max Heapfy data : ");
	for(i = 0 ; i < size ; ++i)
		printf("%d ",a[i]);
	printf("\n");

	return exit_success;
}
