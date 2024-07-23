#include <assert.h>
#include <stdlib.h>

int removeDuplicates(int *nums, int numsSize)
{
    int count = 0, i;
    for (i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i - 1])
            count++;
        else
            nums[i - count] = nums[i];
    }
    return numsSize - count;
}

void proof_harness_removeDuplicates() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }
    int expected_result = __CPROVER_nondet_int();
    int result = removeDuplicates(nums, numsSize);
    assert(result == expected_result);
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
    int expected_result = __CPROVER_nondet_int();
    int result = removeDuplicates(nums, numsSize);
    assert(result == expected_result);
    free(nums);
}

void combined_proof_harness() {
    proof_harness_removeDuplicates();
    proof_harness_main();
}