#include"header.h"

////////////////////////////////////////////////////
//						  //
// Program to find the minimum number of platform //
// Required for given time-table of trains   	  //
//						  //
////////////////////////////////////////////////////

int findMinimumPlatform(int *arr,int *dep,int size)		//Get the Minimum platforms required
{
	quickSort(arr,0,size-1);			//sort both array
	quickSort(dep,0,size-1);		

int i = 1,req = 1,max = 1,j=0;

	while(i<size && j < size)
	{
		if(arr[i] < dep[j])
		{
			++i;
			++req;
	
			if(req > max)
				max = req;
		}

		else
		{
			++j,--req;
		}
	}

	return max;
}

int main()
{
int *arrival = null;
int *departure = null;
int size,i;

	printf("Enter size of time-table.\n");
	scanf("%d",&size);

	arrival = (int*) malloc(sizeof(int)*size);
	departure = (int*) malloc(sizeof(int)*size);

	for(i = 0 ; i < size ; ++i)
	{
		printf("Enter %d train arrival and departure time.\n",i+1);
		scanf("%d%d",&arrival[i],&departure[i]);
	}

	int platform = findMinimumPlatform(arrival,departure,size);

	printf("minimum platform = %d\n",platform);

	return EXIT_SUCCESS;
}
