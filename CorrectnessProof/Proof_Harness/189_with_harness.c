#include <assert.h>
#include <stdlib.h>

void rotate(int *nums, int numsSize, int k)
{
    for (int i = 1; i <= k; i++)
    {
        int j;
        int lastElement;
        lastElement = nums[numsSize - 1];
        for (j = numsSize - 1; j > 0; j--)
        {
            nums[j] = nums[j - 1];
        }
        nums[0] = lastElement;
    }
}

void proof_harness_rotate() {
    int numsSize;
    int k;
    __CPROVER_assume(numsSize >= 1);
    __CPROVER_assume(k >= 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }
    int *nums_copy = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums_copy != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums_copy[i] = nums[i];
    }
    rotate(nums, numsSize, k);
    for (int i = 0; i < numsSize; i++) {
        assert(nums[i] == nums_copy[(i + k) % numsSize]);
    }
    free(nums);
    free(nums_copy);
}

void proof_harness_main() {
    int numsSize = __CPROVER_nondet_int();
    int k = __CPROVER_nondet_int();
    __CPROVER_assume(numsSize >= 1);
    __CPROVER_assume(k >= 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }
    rotate(nums, numsSize, k);
    free(nums);
}

void combined_proof_harness() {
    proof_harness_rotate();
    proof_harness_main();
}