#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int cmpval(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int findDuplicate(int *nums, int numsSize)
{
    int i;
    qsort(nums, numsSize, sizeof(int), cmpval);
    for (i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i + 1])
            return nums[i];
    }
    return nums[i];
}

void proof_harness_findDuplicate() {
    int numsSize;
    __CPROVER_assume(numsSize > 1);
    int *nums = (int *)malloc(numsSize * sizeof(int));
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        __CPROVER_assume(nums[i] >= 0 && nums[i] <= numsSize - 1);
    }
    int result = findDuplicate(nums, numsSize);
    __CPROVER_assert(result >= 0 && result <= numsSize - 1, "findDuplicate returned an invalid value");
    free(nums);
}