#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define max(a,b) (((a)>(b))?(a):(b))

int longestSquareStreakDp(int* numsSet, int numsSetSize, int* dp, long num){
    if (dp[num] != 0){
        return dp[num];
    }

    long numSquare = num * num;

    dp[num] = 1;
    if (numSquare <= numsSetSize && numsSet[numSquare] == 1){
        dp[num] += longestSquareStreakDp(numsSet, numsSetSize, dp, numSquare);
    }

    return dp[num];
}

// Dynamic approach. Up -> down.
// Runtime: O(numsSize)
// Space: O(max(nums))
int longestSquareStreak(int* nums, int numsSize){
    // Find nums maximum
    int numMax = 0;
    for(int i = 0; i < numsSize; i++){
        numMax = max(numMax, nums[i]);
    }

    int* numsSet = calloc(numMax + 1, sizeof(int));
    int* dp = calloc(numMax + 1, sizeof(int));
    
    // Init set of nums
    for(int i = 0; i < numsSize; i++){
        numsSet[nums[i]] = 1;
    }

    // Find result
    int result = -1;
    for(int i = 0; i < numsSize; i++){
        long num = nums[i];
        long numSquare = num * num;

        if (numSquare > numMax || numsSet[numSquare] == 0){
            continue;
        }

        result = max(result, 1 + longestSquareStreakDp(numsSet, numMax, dp, numSquare));
    }

    free(dp);
    free(numsSet);
    return result;
}

void proof_harness_longestSquareStreakDp() {
    int numsSetSize;
    __CPROVER_assume(numsSetSize >= 1 && numsSetSize <= 100);
    int* numsSet = (int*)malloc(sizeof(int) * numsSetSize);
    __CPROVER_assume(numsSet != NULL);
    for (int i = 0; i < numsSetSize; i++) {
        __CPROVER_assume(numsSet[i] >= 0 && numsSet[i] <= 100);
    }
    int* dp = (int*)malloc(sizeof(int) * (numsSetSize + 1));
    __CPROVER_assume(dp != NULL);
    long num;
    __CPROVER_assume(num >= 0 && num <= numsSetSize);
    int result = longestSquareStreakDp(numsSet, numsSetSize, dp, num);
    free(numsSet);
    free(dp);
}

void proof_harness_longestSquareStreak() {
    int numsSize;
    __CPROVER_assume(numsSize >= 1 && numsSize <= 100);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        __CPROVER_assume(nums[i] >= 0 && nums[i] <= 100);
    }
    int result = longestSquareStreak(nums, numsSize);
    free(nums);
}

void proof_harness_main() {
    int result = main();
    assert(result == 0);
}

void combined_proof_harness() {
    proof_harness_longestSquareStreakDp();
    proof_harness_longestSquareStreak();
    proof_harness_main();
}