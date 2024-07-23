#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cmpval(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int *findDuplicates(int *nums, int numsSize, int *returnSize)
{
    int i;
    qsort(nums, numsSize, sizeof(int), cmpval);
    int *retArr = malloc(numsSize * sizeof(int));
    *returnSize = 0;
    for (i = 0; i < numsSize - 1;)
    {
        if (nums[i] == nums[i + 1])
        {
            retArr[*returnSize] = nums[i];
            *returnSize = *returnSize + 1;
            i = i + 2;
        }
        else
        {
            i = i + 1;
        }
    }
    return retArr;
}

void proof_harness_findDuplicates() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int *nums = malloc(numsSize * sizeof(int));
    __CPROVER_assume(nums != NULL);
    int returnSize;
    int *retArr = findDuplicates(nums, numsSize, &returnSize);
    free(nums);
    free(retArr);
}

void proof_harness_cmpval() {
    int a, b;
    __CPROVER_assume(a >= 0);
    __CPROVER_assume(b >= 0);
    int res = cmpval(&a, &b);
    assert(res == a - b);
}

void combined_proof_harness() {
    proof_harness_findDuplicates();
    proof_harness_cmpval();
}