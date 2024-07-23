#include <assert.h>
#include <stdlib.h>

/* Boyer-Moore Majority Vote Algorithm
 * http://www.cs.utexas.edu/~moore/best-ideas/mjrty/ */
int majorityElement(int *nums, int numsSize)
{
    int count = 1;
    int majorNum = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (count == 0)
        {
            majorNum = nums[i];
            count++;
        }
        else if (majorNum == nums[i])
            count++;
        else
            count--;
    }
    return majorNum;
}

void proof_harness_majorityElement() {
    int numsSize;
    __CPROVER_assume(numsSize > 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = rand();
    }
    int result = majorityElement(nums, numsSize);
    free(nums);
}

void proof_harness_main() {
    int numsSize;
    __CPROVER_assume(numsSize > 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = rand();
    }
    int result = majorityElement(nums, numsSize);
    free(nums);
}

void combined_proof_harness() {
    proof_harness_majorityElement();
    proof_harness_main();
}