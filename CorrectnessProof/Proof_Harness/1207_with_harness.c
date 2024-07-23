#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAP_SIZE 2048

int cmpvalue(const void *a, const void *b) { return *(int *)b - *(int *)a; }
bool uniqueOccurrences(int *arr, int arrSize)
{
    int *map = calloc(MAP_SIZE, sizeof(int));
    int i;
    for (i = 0; i < arrSize; i++)
    {
        if (arr[i] < 0)
            map[arr[i] + MAP_SIZE / 2] += 1;
        else
            map[arr[i]] += 1;
    }
    /* number of occurrences is sorted by decreasing order
       Ex: 3 2 1 0 0 0 0 */
    qsort(map, MAP_SIZE, sizeof(int), cmpvalue);
    i = 0;
    while (map[i])
    {
        if (map[i] == map[i + 1])
            return 0;
        i++;
    }
    return 1;
}

void proof_harness_uniqueOccurrences() {
    int arrSize;
    __CPROVER_assume(arrSize >= 0);
    int *arr = (int *)malloc(arrSize * sizeof(int));
    __CPROVER_assume(arr != NULL);

    for (int i = 0; i < arrSize; i++) {
        __CPROVER_assume(arr[i] >= -MAP_SIZE / 2 && arr[i] <= MAP_SIZE / 2 - 1);
    }
    bool result = uniqueOccurrences(arr, arrSize);
    free(arr);
}

void proof_harness_main() {
    int arrSize;
    __CPROVER_assume(arrSize >= 0);
    int *arr = (int *)malloc(arrSize * sizeof(int));
    __CPROVER_assume(arr != NULL);

    for (int i = 0; i < arrSize; i++) {
        __CPROVER_assume(arr[i] >= -MAP_SIZE / 2 && arr[i] <= MAP_SIZE / 2 - 1);
    }
    bool result = uniqueOccurrences(arr, arrSize);
    free(arr);
}

void combined_proof_harness() {
    proof_harness_uniqueOccurrences();
    proof_harness_main();
}