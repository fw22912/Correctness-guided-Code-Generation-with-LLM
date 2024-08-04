
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void show_data(int *arr, long len)
{
    for (long i = 0; i < len; i++) printf("%3d ", arr[i]);
    printf("\n");
}


inline void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}


void shell_sort(int *array, long LEN)
{
    const int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
    const int gap_len = 8;
    long i, j, g;

    for (g = 0; g < gap_len; g++)
    {  
        int gap = gaps[g];
        for (i = gap; i < LEN; i++)
        {  
            int tmp = array[i];

            for (j = i; j >= gap && (array[j - gap] - tmp) > 0; j -= gap)
                array[j] = array[j - gap];
            array[j] = tmp;
        }
    }
#ifdef DEBUG
    for (i = 0; i < LEN; i++) printf("%s\t", data[i]);
#endif
}



int main(int argc, char *argv[])
{
    int i;
    long size = 500;
    if (argc == 2)
        size = atol(argv[1]);
    else if (argc > 2)
        fprintf(stderr, "Usage: ./shell_sort [number of values]\n");

    int *array = (int *)malloc(size * sizeof(int));
    int range = 500;  
    double time_spent;

    srand(time(NULL));  
    for (i = 0; i < size; i++)
        
        array[i] = rand() % range + 1;

    show_data(array, size);   
    clock_t t1 = clock();     
    shell_sort(array, size);  
    clock_t t2 = clock();     

    printf("Data Sorted\n");
    show_data(array, size);  

    printf("Time spent sorting: %.4g s\n", (t2 - t1) / CLOCKS_PER_SEC);

    free(array);
    return 0;
}
