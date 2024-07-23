#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int i, j;
    int *ret = calloc(2, sizeof(int));
    for (i = 0; i < numsSize; i++)
    {
        int key = target - nums[i];
        for (j = i + 1; j < numsSize; j++)
            if (nums[j] == key)
            {
                ret[0] = i;
                ret[1] = j;
            }
    }
    *returnSize = 2;
    return ret;
}

void proof_harness_twoSum() {
    int numsSize;
    int target;
    int returnSize;
    
    __CPROVER_assume(numsSize >= 0);
    
    int *nums = malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    
    for (int i = 0; i < numsSize; i++) {
        nums[i] = rand();
    }
    
    target = rand();
    
    int *ret = twoSum(nums, numsSize, target, &returnSize);
    
    assert(returnSize == 2);
    
    free(nums);
    free(ret);
}

void combined_proof_harness() {
    proof_harness_twoSum();
}