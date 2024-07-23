#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int search(int *nums, int numsSize, int target)
{
    int low = 0, high = numsSize - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (target > nums[mid])
        {
            low = mid + 1;
        }
        else if (target < nums[mid])
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

/* Another solution: Using bsearch() */
int cmpint(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int search(int *nums, int numsSize, int target)
{
    int *ret = bsearch(&target, nums, numsSize, sizeof(int), cmpint);
    if (ret)
        return (ret - nums);
    else
        return -1;
}

void proof_harness_search() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }
    int target = __CPROVER_nondet_int();
    int result = search(nums, numsSize, target);
    if (result != -1) {
        assert(nums[result] == target);
    }
    free(nums);
}

void combined_proof_harness() {
    proof_harness_search();
}

int main() {
    combined_proof_harness();
    return 0;
}