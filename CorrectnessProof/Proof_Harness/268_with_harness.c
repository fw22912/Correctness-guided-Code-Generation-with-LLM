#include <assert.h>
#include <stdlib.h>

int missingNumber(int *nums, int numsSize)
{
    int i, actual_sum = 0, sum = 0;
    for (i = 0; i < numsSize; i++)
    {
        sum = sum + nums[i];
        actual_sum = actual_sum + i;
    }
    return actual_sum + numsSize - sum;
}

void proof_harness_missingNumber() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL); 
    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }
    int expected_result = missingNumber(nums, numsSize);
    int actual_result = missingNumber(nums, numsSize);
    assert(expected_result == actual_result);
    free(nums);
}

int main() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL); 
    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }
    int result = missingNumber(nums, numsSize);
    free(nums);
    return 0;
}

void proof_harness_main() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL); 
    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }
    main();
    free(nums);
}


void combined_proof_harness() {
    proof_harness_missingNumber();
    proof_harness_main();
}