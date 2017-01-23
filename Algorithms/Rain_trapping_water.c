#include"header.h"

///////////////////////////////////////////////
//					     //
// Program to count water trap in given non- //
// Negative integer represent as a elevation //
//					     //
///////////////////////////////////////////////

int max(int a,int b)
{
	return a > b ? a : b;
}

int min(int a,int b)
{
	return a < b ? a : b;
}

void buildRightArray(int *a,int rmax[],int size)
{
int i;

	rmax[size-1] = a[size-1];

 size -= 2;

	for(i = size ; i >= 0 ; --i)
		rmax[i] = max(a[i],rmax[i+1]);
}

void buildLeftArray(int *a,int lmax[],int size)
{
int i;

	lmax[0] = a[0];

	for(i = 1 ; i < size ; ++i)
		lmax[i] = max(a[i],lmax[i-1]);
	
}

int calculateWater(int *a,int size)
{
int lmax[size],rmax[size],i,water = 0;

	buildLeftArray(a,lmax,size);
	buildRightArray(a,rmax,size);

	for(i = 0 ; i < size ; ++i)
	{
		water += (min(lmax[i],rmax[i]) - a[i]);
	}

	return water;
}

int main()
{
int *a = null;
int size,i;

	printf("Enter size of array.\n");
	scanf("%d",&size);

	a = (int*) malloc(sizeof(int)*size);

	for(i = 0 ; i < size ; ++i)
		scanf("%d",&a[i]);

	int res = calculateWater(a,size);

	printf("Res = %d\n",res);

	return EXIT_SUCCESS;
}
