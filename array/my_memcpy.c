#include<stdio.h>
#include<stdlib.h>

///////////////////////////////////////////////
//					     //
// Implementing memcpy user defined function //
//					     //
///////////////////////////////////////////////

void my_memcpy(void *dest,void *src,int size)
{
int i;
char *destination = (char*) dest;
char *source = (char*) src;

	for(i = 0 ; i < size ; ++i)
	{
		destination[i] = source[i];
	}

}

int main()
{
int source[15] = {0},destination[15];
int i;

	srand(getpid());

	for(i = 0 ; i < 15 ; ++i)
		source[i] = rand()%15;

	for(i = 0 ; i < 15 ; ++i)
		printf("%d ",source[i]);
	printf("\n");

	my_memcpy(destination,source,12);

	for(i = 0 ; i < 12 ; ++i)
		printf("%d ",destination[i]);
	printf("\n");

	return EXIT_SUCCESS;
}
