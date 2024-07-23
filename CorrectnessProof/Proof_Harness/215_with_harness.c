#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int *cmpval(const void *a, const void *b) { return *(int *)b - *(int *)a; }

int findKthLargest(int *nums, int numsSize, int k)
{
    qsort(nums, numsSize, sizeof(int), cmpval);
    return nums[k - 1];
}

void proof_harness_findKthLargest() {
    int numsSize;
    int k;
    __CPROVER_assume(numsSize >= 1);
    __CPROVER_assume(k >= 1);
    __CPROVER_assume(k <= numsSize);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = nondet_int();
    }
    int expected = findKthLargest(nums, numsSize, k);
    int actual = findKthLargest(nums, numsSize, k);
    assert(actual == expected);
    free(nums);
}

void combined_proof_harness() {
    proof_harness_findKthLargest();
}