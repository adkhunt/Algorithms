#include"header.h"

/////////////////////////////////////////////
//					   //
// Program to rotate an array in O(n) time //
//					   //
/////////////////////////////////////////////

void reverse(int *a,int start,int end)
{
int temp;

	while(start<end)
	{
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		++start,--end;
	}
}

void rotateArray2(int *a,int size,int rotation) // Reverse array in O(n) time 
{
	reverse(a,0,rotation-1);
	reverse(a,rotation,size-1);
	reverse(a,0,size-1);
}

void rotateArrayOn(int *a,int size , int rotation) // function to rotate array in O(1) extra space
{
int i,j,temp,k;

	for(i = 0 ; i < greatestCd(rotation,size) ; ++i)
	{
		j = i;
		temp = a[i];

		while(1)
		{
			k = j + rotation;
			if (k >= size)
				k = k - size;
			if (k == i)
				break;
			a[j] = a[k];
			j = k;
		}
		a[j] = temp;
	}
}

int greatestCd(int a,int b)
{
	if(b == 0)
		return a;

	greatestCd(b,a%b);
}

void rotateArray(int *a,int size, int rotation) // function to rotate array with O(k) extra space
{
int i,temp[rotation],j = 0;

	for(i = 0 ; i < rotation ; ++i)
		temp[i] = a[i];

	for(i = rotation ; i < size ; ++i)
	{
		a[j++] = a[i];
	}

	for(i = 0 ; i < rotation ; ++i)
		a[j++] = temp[i];
}

int main()
{
int *arr = null;
int size,i,rotate;

	printf("Enter size of array.\n");
	scanf("%d",&size);

	arr = (int*) malloc(sizeof(int)*size);

	printf("Enter element in array.\n");
	for(i = 0 ; i < size ; ++i)
		scanf("%d",&arr[i]);

	printf("Enter number of rotation.\n");
	scanf("%d",&rotate);

	rotateArray2(arr,size,rotate);

	printf("Rotated array : ");
	for(i = 0 ; i <size ; ++i)
		printf("%d ",arr[i]);

	printf("\n");

	return exit;
}
