

#include <assert.h>     
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       
#include <inttypes.h>   


void swap(int8_t *first, int8_t *second)
{
    int8_t temp = *first;
    *first = *second;
    *second = temp;
}


uint8_t findIndex(const int8_t *arr, const uint8_t size)
{
    if (size == 1)
    {
        return 0;
    }

    
    uint8_t min_index = findIndex(arr, size - 1);

    if (arr[size - 1] < arr[min_index])
    {
        min_index = size - 1;
    }

    return min_index;
}


void selectionSort(int8_t *arr, const uint8_t size)
{
    if (size <= 1)
    {
        return;
    }

    
    uint8_t min_index = findIndex(arr, size);
    

    if (min_index != 0)
    {
        swap(&arr[0], &arr[min_index]);
    }

    
    selectionSort(arr + 1, size - 1);
}


static void test()
{
    const uint8_t size = 10;
    int8_t *arr = (int8_t *)calloc(size, sizeof(int8_t));

    
    for (uint8_t i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    selectionSort(arr, size);
    for (uint8_t i = 0; i < size - 1; ++i)
    {
        assert(arr[i] <= arr[i + 1]);
    }
    free(arr);
}


int main()
{
    
    srand(time(NULL));

    test();  
    return 0;
}
