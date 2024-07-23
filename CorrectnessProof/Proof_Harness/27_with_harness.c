#include <assert.h>
#include <stdlib.h>

int removeElement(int *nums, int numsSize, int val)
{
    int i, start = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
            nums[start++] = nums[i];
    }
    return start;
}

void proof_harness_removeElement() {
    int numsSize;
    int val;
    __CPROVER_assume(numsSize >= 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL); 
    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }
    val = __CPROVER_nondet_int();
    int expected_size = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            expected_size++;
        }
    }
    int result = removeElement(nums, numsSize, val);
    assert(result == expected_size);
    free(nums);
}

void combined_proof_harness() {
    proof_harness_removeElement();
}