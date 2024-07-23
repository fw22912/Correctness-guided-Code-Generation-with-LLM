#include <assert.h>
#include <stdlib.h>

int maxcmp(int a, int b) { return a >= b ? a : b; }

int maxSubArray(int *nums, int numsSize)
{
    int maxSoFar = nums[0], maxEndingHere = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        maxEndingHere = maxcmp(maxEndingHere + nums[i], nums[i]);
        maxSoFar = maxcmp(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}

void proof_harness_maxSubArray() {
    int numsSize;
    __CPROVER_assume(numsSize >= 1);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);

    for (int i = 0; i < numsSize; i++) {
        nums[i] = rand();
    }
    
    int expected_result = nums[0];
    for (int i = 1; i < numsSize; i++) {
        expected_result = maxcmp(expected_result, nums[i]);
    }

    int result = maxSubArray(nums, numsSize);
    assert(result == expected_result);

    free(nums);
}


void proof_harness_maxcmp() {
    int a = rand();
    int b = rand();
    int expected_result = a >= b ? a : b;

    int result = maxcmp(a, b);
    assert(result == expected_result);
}

void proof_harness_main() {
    int numsSize = 5;
    int nums[5] = {1, -2, 3, -4, 5};
    int expected_result = 6;

    int result = maxSubArray(nums, numsSize);
    assert(result == expected_result);
}

void combined_proof_harness() {
    proof_harness_maxcmp();
    proof_harness_maxSubArray();
    proof_harness_main();
}