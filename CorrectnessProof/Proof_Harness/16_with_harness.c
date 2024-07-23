#include <stdlib.h> // for qsort()
#include <assert.h>

int cmp(const void* a, const void* b) {
    const int *A = a, *B = b;
    return (*A > *B) - (*A < *B);
}

int threeSumClosest(int* nums, int nums_size, int target) {
    int i, j, k, result, sum3;
    qsort(nums, nums_size, sizeof(int), cmp);
    result = nums[0] + nums[1] + nums[2];
    for (i = 0; i < nums_size - 2; i++) {
        j = i + 1;
        k = nums_size - 1;
        while (j < k) {
            sum3 = nums[i] + nums[j] + nums[k];
            if (abs(target - sum3) < abs(target - result)) {
                result = sum3;
            }
            if (sum3 < target) {
                j++;
            } else if (sum3 > target) {
                k--;
            } else {
                return sum3;
            }
        }
    }
    return result;
}

void proof_harness_threeSumClosest() {
    int nums_size;
    __CPROVER_assume(nums_size > 2);
    int *nums = (int*)malloc(sizeof(int) * nums_size);
    __CPROVER_assume(nums != NULL);
    int target;
    for (int i = 0; i < nums_size; i++) {
        nums[i] = __CPROVER_nondet_int();
    }
    target = __CPROVER_nondet_int();
    int expected = threeSumClosest(nums, nums_size, target);
    int result = threeSumClosest(nums, nums_size, target);
    assert(result == expected);
    free(nums);
}

void proof_harness_cmp() {
    int a = __CPROVER_nondet_int();
    int b = __CPROVER_nondet_int();
    int result = cmp(&a, &b);
    if (a > b) {
        assert(result == 1);
    } else if (a < b) {
        assert(result == -1);
    } else {
        assert(result == 0);
    }
}

void combined_proof_harness() {
    proof_harness_threeSumClosest();
    proof_harness_cmp();
}