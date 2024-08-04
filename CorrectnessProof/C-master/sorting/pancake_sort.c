
#include <stdio.h>
#include <stdlib.h>


void flip(int arr[], int i)
{
    int temp, start = 0;

    while (start < i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}


int findMax(int arr[], int n)
{
    int maxElementIdx, i;

    for (maxElementIdx = 0, i = 0; i < n; ++i)
        if (arr[i] > arr[maxElementIdx])
            maxElementIdx = i;

    return maxElementIdx;
}


void pancakeSort(int *arr, int n)
{
    
    for (int curr_size = n; curr_size > 1; --curr_size)
    {
        
        int maxElementIdx = findMax(arr, curr_size);

        
        
        if (maxElementIdx != curr_size - 1)
        {
            
            flip(arr, maxElementIdx);

            
            flip(arr, curr_size - 1);
        }
    }
}


void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

#define N 50


int main()
{
    int arr[N];
    for (int i = 0; i < N; i++)
        arr[i] = rand() % (N << 1); 

    printf("Original array: ");
    display(arr, N);

    pancakeSort(arr, N);
    printf("Sorted array: ");
    display(arr, N);

    return 0;
}