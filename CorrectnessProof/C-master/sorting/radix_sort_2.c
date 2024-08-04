
#include <stdio.h>
#include <stdlib.h>

#define range 10  


int MAX(int *ar, int size)
{
    int i, max = ar[0];
    for (i = 0; i < size; i++)
    {
        if (ar[i] > max)
            max = ar[i];
    }
    return max;
}


void countSort(int *arr, int n, int place)
{
    int i, freq[range] = {0};
    int *output = (int *)malloc(n * sizeof(int));

    
    for (i = 0; i < n; i++) freq[(arr[i] / place) % range]++;

    
    
    for (i = 1; i < range; i++) freq[i] += freq[i - 1];

    
    for (i = n - 1; i >= 0; i--)
    {
        output[freq[(arr[i] / place) % range] - 1] = arr[i];
        freq[(arr[i] / place) % range]--;
    }

    
    
    for (i = 0; i < n; i++) arr[i] = output[i];
    free(output);
}


void radixsort2(int *arr, int n,
                int max)  
{
    int mul = 1;
    while (max)
    {
        countSort(arr, n, mul);
        mul *= 10;
        max /= 10;
    }
}

void display(int *arr, int N)
{
    for (int i = 0; i < N; i++) printf("%d, ", arr[i]);
    putchar('\n');
}

int main(int argc, const char *argv[])
{
    int n;
    printf("Enter size of array:\n");
    scanf("%d", &n);  

    printf("Enter the elements of the array\n");
    int i;
    int *arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    display(arr, n);  

    int max;
    max = MAX(arr, n);

    radixsort2(arr, n, max);

    printf("Sorted array: ");
    display(arr, n);  

    free(arr);
    return 0;
}
