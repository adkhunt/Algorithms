#include"header.h"

///////////////////////////////////////////////////////////////
//							     //
// sort array in such manner that all even index number sort //
// in increasing order and odd index number sort in decreas- //
// ing order/* this program take O(n) extra space and        //
// O(nlogn) time complexity				     //
//							     //
///////////////////////////////////////////////////////////////

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int getPartition(int *a,int start,int end)
{
	int i = start,index = start,pivot = end,temp;

	while(i<end)
	{
		if(a[pivot] > a[i])
		{
			swap(a+i,a+index);
			++index;
		}

		++i;
	}

	swap(a+pivot,a+index);
	
	return index;
}

void sort(int *a,int start,int end)		//quick sort function to sort numbers
{
	if(start<end)
	{
		int part = getPartition(a,start,end);
		sort(a,start,part-1);
		sort(a,part+1,end);
	}
}

void sort_even_odd(int *arr,int size)
{
int odd_size;					//store the odd index size
int even_size = odd_size = (size/2);		//store the even index size

	if(size&1)				//if size is odd
		++even_size;			//we incerement even array size by 1

int even_array[even_size];			//store the even indexed element
int odd_array[odd_size];			//store the odd ondexed element
int i=0,j=0,k=0;

	while(k<size)
	{
		if(k&1)
		{
			odd_array[i++] = arr[k];
		}
		else
		{
			even_array[j++] = arr[k];
		}
		++k;
	}

	sort(even_array,0,even_size-1);		//sort both array
	sort(odd_array,0,odd_size-1);

	k = 0,i = odd_size-1,j=0;
	while(k<size)
	{
		if(k&1)
		{
			arr[k] = odd_array[i--];
		}

		else
		{
			arr[k] = even_array[j++];
		}
		++k;
	}
}

int main()
{
int *arr = null,size,i;

	printf("Enter size of array : ");
	scanf("%d",&size);

	arr = (int*) malloc(sizeof(int)*size);

	printf("Enter array element : ");
	for(i =0 ; i < size ; ++i)
		scanf("%d",&arr[i]);

	sort_even_odd(arr,size);

	printf("Resultant array : ");

	for(i = 0 ; i < size ; ++i)
		printf("%d ",arr[i]);
	printf("\n");

	return EXIT_SUCCESS;
}
