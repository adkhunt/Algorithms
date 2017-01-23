#include"header.h"

/////////////////////////////////////////////
//					   //
// Program to search pivot index in sorted //
// Rotated array in O(log n) time	   //
//					   //
/////////////////////////////////////////////

int getPivot(int *a,int start,int end)
{
	if(start > end)
		return -1;

	if(start == end)
		return start;

	int mid = (start + end)/2;

	if(mid < end && a[mid] > a[mid+1])
		return mid;

	if(mid > start && a[mid] < a[mid-1])
		return mid-1;

	if(a[start] >= a[mid])
		return getPivot(a,start,mid-1);

	return getPivot(a,mid+1,end);
}

int searchPivot(int *a,int size)
{
	return getPivot(a,0,size);
}

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

	printf("Pivot index = %d\n",pivot);

	return EXIT_SUCCESS;
}
