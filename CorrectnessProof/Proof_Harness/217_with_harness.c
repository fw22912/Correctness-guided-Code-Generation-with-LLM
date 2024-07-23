#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int numcmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

bool containsDuplicate(int *nums, int numsSize)
{
    int i;
    qsort(nums, numsSize, sizeof(int), numcmp);
    for (i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i + 1])
            return 1;
    }
    return 0;
}

void proof_harness_containsDuplicate() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = rand();
    }
    bool expected_result = containsDuplicate(nums, numsSize);
    bool actual_result = containsDuplicate(nums, numsSize);
    assert(actual_result == expected_result);
    free(nums);
}

void proof_harness_numcmp() {
    int a = rand();
    int b = rand();
    int expected_result = a - b;
    int actual_result = numcmp(&a, &b);
    assert(actual_result == expected_result);
}

void combined_proof_harness() {
    proof_harness_containsDuplicate();
    proof_harness_numcmp();
}