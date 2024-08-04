

#include <assert.h>     
#include <stdbool.h>    
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       
#include <inttypes.h>   


void swap(int32_t *first, int32_t *second)
{
    int32_t temp = *first;
    *first = *second;
    *second = temp;
}


void oddEvenSort(int *arr, int size)
{
    bool isSorted = false;
    while(!isSorted)
    {
        isSorted = true;
        int32_t i;

        
        for(i = 0; i <= size - 2; i += 2)
        {
            if(arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
                isSorted = false;
            }
        }

        
        for(i = 1; i <= size - 2; i += 2)
        {
            if(arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
                isSorted = false;
            }
        }
    }
}


static void test()
{
    int32_t arr1[] = {-9, 2, 3, 1};
    int32_t arr1Soln[] = {-9, 1, 2, 3};
    int32_t arr2[] = {9, 7, 5, 3, 8, 2, 1, 4, 0, 6};
    int32_t arr2Soln[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    oddEvenSort(arr1, 4);
    oddEvenSort(arr2, 10);

     for (int32_t i = 0; i < 4; i++)
     {
         assert(arr1[i] == arr1Soln[i]);    
     }

    for (int32_t i = 0; i < 10; i++)
    {
        assert(arr2[i] == arr2Soln[i]);    
    }
    printf("All tests have passed!\n");
}


int main()
{
    test();  
    return 0;
}
