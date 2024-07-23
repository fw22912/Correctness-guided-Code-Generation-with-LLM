#include <assert.h>
#include <stdlib.h>

void duplicateZeros(int *arr, int arrSize)
{
    int i, start = 0;
    int *tmp = malloc(arrSize * sizeof(int));
    /* Copy arr into tmp arr */
    for (i = 0; i < arrSize; i++)
    {
        tmp[i] = arr[i];
    }
    i = 0;
    for (start = 0; start < arrSize; start++)
    {
        arr[start] = tmp[i];
        if (tmp[i] == 0)
        {
            start++;
            if (start < arrSize)
                arr[start] = 0;
        }
        i++;
    }
}

void proof_harness_duplicateZeros() {
    int arrSize;
    __CPROVER_assume(arrSize > 0);
    int *arr = (int *)malloc(arrSize * sizeof(int));
    __CPROVER_assume(arr != NULL); 
    for (int i = 0; i < arrSize; i++) {
        arr[i] = __CPROVER_nondet_int(); 
    }
    duplicateZeros(arr, arrSize);
    free(arr); 
}

int main() {
    proof_harness_duplicateZeros();
    return 0;
}

void combined_proof_harness() {
    proof_harness_duplicateZeros();
}