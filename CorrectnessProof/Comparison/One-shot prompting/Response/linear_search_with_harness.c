#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int linearsearch(int *arr, int size, int val)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == val)
            return 1;
    }
    return 0;
}

int main()
{
    int n, i, v;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);  // Taking input for the size of Array

    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter the contents for an array of size %d:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);  // accepts the values of array elements until the
                             // loop terminates//

    printf("Enter the value to be searched:\n");
    scanf("%d", &v);  // Taking input the value to be searched
    if (linearsearch(a, n, v))
        printf("Value %d is in the array.\n", v);
    else
        printf("Value %d is not in the array.\n", v);

    free(a);
    return 0;
}

void proof_harness_linearsearch() {
    int size;
    __CPROVER_assume(size >= 0);
    int *arr = (int *)malloc(size * sizeof(int));
    __CPROVER_assume(arr != NULL);
    int val;
    
    for (int i = 0; i < size; i++) {
        arr[i] = __CPROVER_nondet_int();
    }
    
    int expected_result = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            expected_result = 1;
            break;
        }
    }
    
    int result = linearsearch(arr, size, val);
    assert(result == expected_result);
    
    free(arr);
}