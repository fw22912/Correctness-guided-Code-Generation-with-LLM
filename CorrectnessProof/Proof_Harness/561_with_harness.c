#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpval(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int arrayPairSum(int *nums, int numsSize)
{
    int sum = 0, i;
    qsort(nums, numsSize, sizeof(int), cmpval);
    for (i = 0; i < numsSize; i = i + 2) sum = sum + nums[i];
    return sum;
}

void proof_harness_arrayPairSum() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = rand();
    }
    int expected_sum = 0;
    for (int i = 0; i < numsSize; i = i + 2) {
        expected_sum += nums[i];
    }
    int actual_sum = arrayPairSum(nums, numsSize);
    assert(actual_sum == expected_sum);
    free(nums);
}

void proof_harness_main() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = rand();
    }
    int result = arrayPairSum(nums, numsSize);
    free(nums);
}

void combined_proof_harness() {
    proof_harness_arrayPairSum();
    proof_harness_main();
}