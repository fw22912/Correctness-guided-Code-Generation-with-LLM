
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int key = arr[i];
        
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        arr[j + 1] = key;
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
    insertionSort(arr, size);
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
