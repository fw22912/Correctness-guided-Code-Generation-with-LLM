#include <assert.h>
#include <stdlib.h>

/**
 * Time complexity: O(log n).
 * Space complexity: O(1).
 * @details The array has a pattern that consists in of the existing sub-array to 
 *          the left of the non-repeating number will satisfy the condition that 
 *          each pair of repeated elements have their first occurrence at the even index
 *          and their second occurrence at the odd index, and that the sub-array to 
 *          the right of the non-repeating number will satisfy the condition that 
 *          each pair of repeated elements have their first occurrence at the odd index
 *          and their second occurrence at the even index. With this pattern in mind, 
 *          we can solve the problem using binary search.
 */

int singleNonDuplicate(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int mid = (right + left) / 2;
        if (mid % 2 == 0) {
            if (nums[mid] == nums[mid + 1])
                left = mid + 2;
            else
                right = mid;
        }
        else {
            if (nums[mid] == nums[mid - 1])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return nums[left];
}


void proof_harness_singleNonDuplicate() {
    int numsSize;
    __CPROVER_assume(numsSize > 0);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);

    for (int i = 0; i < numsSize; i++) {
        __CPROVER_assume(i % 2 == 0 ? nums[i] != nums[i + 1] : nums[i] != nums[i - 1]);
    }

    int result = singleNonDuplicate(nums, numsSize);
    int expected_result = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0 ? nums[i] != nums[i + 1] : nums[i] != nums[i - 1]) {
            expected_result = nums[i];
            break;
        }
    }

    assert(result == expected_result);
    free(nums);
}


int main() {
    proof_harness_singleNonDuplicate();
    return 0;
}

void combined_proof_harness() {
    proof_harness_singleNonDuplicate();
}