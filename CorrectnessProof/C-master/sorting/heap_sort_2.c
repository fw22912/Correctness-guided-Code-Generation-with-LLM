

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


void heapifyDown(int8_t *arr, const uint8_t size)
{
    uint8_t i = 0;

    while (2 * i + 1 < size)
    {
        uint8_t maxChild = 2 * i + 1;

        if (2 * i + 2 < size && arr[2 * i + 2] > arr[maxChild])
        {
            maxChild = 2 * i + 2;
        }

        if (arr[maxChild] > arr[i])
        {
            swap(&arr[i], &arr[maxChild]);
            i = maxChild;
        }
        else
        {
            break;
        }
    }
}


void heapifyUp(int8_t *arr, uint8_t i)
{
    while (i > 0 && arr[(i - 1) / 2] < arr[i])
    {
        swap(&arr[(i - 1) / 2], &arr[i]);
        i = (i - 1) / 2;
    }
}


void heapSort(int8_t *arr, const uint8_t size)
{
    if (size <= 1)
    {
        return;
    }

    for (uint8_t i = 0; i < size; i++)
    {
        

        
        heapifyUp(arr, i);
    }

    for (uint8_t i = size - 1; i >= 1; i--)
    {
        
        swap(&arr[0], &arr[i]);

        
        heapifyDown(arr, i);

    }
}


static void test()
{
    const uint8_t size = 10;
    int8_t *arr = (int8_t *)calloc(size, sizeof(int8_t));

    
    for (uint8_t i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    heapSort(arr, size);
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
