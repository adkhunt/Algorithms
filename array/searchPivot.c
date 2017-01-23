#include"header.h"

int main()
{
int *arr = null;
int size,i;

	printf("Enter size of array.\n");
	scanf("%d",&size);

	arr = (int*) malloc(sizeof(int)*size);

	printf("Enter element in array in sorted manner.\n");
	for(i = 0 ; i < size ; ++i)
		scanf("%d",&arr[i]);

	int pivot = searchPivot(arr,size);

	return EXIT_SUCCESS;
}
