#include<stdio.h>
#include<stdbool.h>

typedef struct pair{

   int start, end;
   bool isFound;
} elem_pair;

elem_pair get_sum_subset(int size, int array[size], const int sum)
{
   elem_pair pair = {0, 1, true};
   int i, curSum = array[0];

   for(i = 1 ; i <= size ; ++i){

      while (curSum > sum && pair.start < i - 1){

         curSum -= array[pair.start];
         ++pair.start;
      }


      if(sum == curSum){
         pair.end = i-1;
         return pair;
      }

      if(i < size)
         curSum += array[i];
   }

   pair.isFound = false;
   return pair;
}

int main()
{
int array[] = {15, 2, 4, 8, 9, 5, 10, 23};
int sum = 23;

   int size = sizeof(array) / sizeof(array[0]);

   elem_pair pair = get_sum_subset(size, array, sum);

   if(pair.isFound)
      printf("Sum found at %d to %d indexs\n",pair.start, pair.end);
   else
      printf("No sum subarray found in the array.\n");

   return 0;
}
