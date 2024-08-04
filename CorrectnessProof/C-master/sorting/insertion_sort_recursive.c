
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void RecursionInsertionSort(int *arr, int size)
{
    if(size <= 0)
    {
        return;
    }
    
    
    RecursionInsertionSort(arr,size-1);
    
    int key = arr[size-1];
    int j = size-2;
    
    while(j >= 0 && arr[j] > key)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
}


static void test()
{
    const int size = rand() % 500; 
    int *arr = (int *)calloc(size, sizeof(int));

      
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 100) - 50;
    }
    RecursionInsertionSort(arr, size);
    for (int i = 0; i < size  ; ++i)
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
