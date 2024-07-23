#include <assert.h>
#include <stdlib.h>

void moveZeroes(int *nums, int numsSize)
{
    int i = 0, start = 0;

    for (i = 0; i < numsSize; i++)
    {
        if (nums[i])
            nums[start++] = nums[i];
    }

    for (start; start < numsSize; start++)
    {
        nums[start] = 0;
    }
}

void proof_harness_moveZeroes() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL); 

    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }

    int *original_nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(original_nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        original_nums[i] = nums[i];
    }

    moveZeroes(nums, numsSize);

    int count_zeros_original = 0;
    int count_zeros_modified = 0;

    for (int i = 0; i < numsSize; i++) {
        if (original_nums[i] == 0) {
            count_zeros_original++;
        }
        if (nums[i] == 0) {
            count_zeros_modified++;
        }
    }

    assert(count_zeros_original == count_zeros_modified);

    int j = 0;
    for (int i = 0; i < numsSize; i++) {
        if (original_nums[i] != 0) {
            assert(nums[j] == original_nums[i]);
            j++;
        }
    }

    free(nums);
    free(original_nums);
}

int main() {
    proof_harness_moveZeroes();
    return 0;
}

void combined_proof_harness() {
    proof_harness_moveZeroes();
}