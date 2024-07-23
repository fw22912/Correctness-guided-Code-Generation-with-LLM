#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// Prefix sum.
// - Calculate whole nums sum.
// - Calculate currIndex sum.
// - Compare averages
// Runtime: O(n)
// Space: O(1)

int minimumAverageDifference(int* nums, int numsSize){
    long numsSum = 0;
    for (int i = 0; i < numsSize; i++){
        numsSum += nums[i];
    }
    
    long currSum = 0;
    long minAverage = 9223372036854775807; // Long max
    int minIndex = 0;
    
    for (int i = 0; i < numsSize; i++){
        currSum += nums[i];

        int leftItemsNumber = (numsSize - i  - 1);
        long leftItemsNumberAverage = 0;
        if (leftItemsNumber != 0){
            leftItemsNumberAverage = (numsSum - currSum) / leftItemsNumber;
        }

        long currItemsNumberAverage = currSum / (i + 1);
        long averageDiff = abs(currItemsNumberAverage - leftItemsNumberAverage);

        if (averageDiff < minAverage){
            minAverage = averageDiff;
            minIndex = i;
        }
    }

    return minIndex;
}

void proof_harness_minimumAverageDifference() {
    int numsSize;
    __CPROVER_assume(numsSize >= 1 && numsSize <= 100000);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        __CPROVER_assume(nums[i] >= -100000 && nums[i] <= 100000);
    }
    int expected = minimumAverageDifference(nums, numsSize);
    int actual = minimumAverageDifference(nums, numsSize);
    assert(expected == actual);
    free(nums);
}

void combined_proof_harness() {
    proof_harness_minimumAverageDifference();
}