#include <assert.h>
#include <stdlib.h>

int findLengthOfLCIS(int *nums, int numsSize)
{
    int maxval = 1, i, count = 1;
    if (numsSize == 0)
        return 0;
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            count++;
            if (count >= maxval)
                maxval = count;
        }
        else
        {
            count = 1;
        }
    }
    return maxval;
}

void proof_harness_findLengthOfLCIS() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL); 
    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }
    int expected = findLengthOfLCIS(nums, numsSize);
    int actual = findLengthOfLCIS(nums, numsSize);
    assert(expected == actual);
    free(nums);
}


void proof_harness_main() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL); 
    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }
    int expected = findLengthOfLCIS(nums, numsSize);
    int actual = findLengthOfLCIS(nums, numsSize);
    assert(expected == actual);
    free(nums);
}


void combined_proof_harness() {
    proof_harness_findLengthOfLCIS();
    proof_harness_main();
}