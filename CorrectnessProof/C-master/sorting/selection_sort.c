
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}


void selectionSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(arr + i, arr + min_index);
        }
    }
}


static void test()
{
    const int size = rand() % 500; 
    int *arr = (int *)calloc(size, sizeof(int));

    
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 100) - 50; 
    }
    selectionSort(arr, size);
    for (int i = 0; i < size - 1; ++i)
    {
        assert(arr[i] <= arr[i + 1]);
    }
    free(arr);
}


int main(int argc, const char *argv[])
{
    
    srand(time(NULL));
    test();
    return 0;
}
