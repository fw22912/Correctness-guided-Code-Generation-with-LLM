#include <assert.h>
#include <stdlib.h>

int singleNumber(int *nums, int numsSize)
{
    int i, result = 0;
    for (i = 0; i < numsSize; i++) result = result ^ nums[i];
    return result;
}

void proof_harness_singleNumber() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = rand();
    }
    int result = singleNumber(nums, numsSize);
    free(nums);
}

void proof_harness_main() {
    int numsSize = 1;
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    nums[0] = 2;
    int result = singleNumber(nums, numsSize);
    assert(result == 2);
    free(nums);
}

void combined_proof_harness() {
    proof_harness_singleNumber();
    proof_harness_main();
}