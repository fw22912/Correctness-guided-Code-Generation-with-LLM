#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define max(a,b) (((a)>(b))?(a):(b))

long getSum(int* nums, int numsSize, int divizor){
    long result = 0;
    for (int i = 0; i < numsSize; i++){
        int value = nums[i] / divizor;
        if (value * divizor != nums[i]){
            value++;
        }

        result += value;
    }

    return result;
}

// Divide and conquer
// Runtime: O(n*log(n))
// Space: O(1)
int smallestDivisor(int* nums, int numsSize, int threshold){
    int maxNum = 0;
    for (int i = 0; i < numsSize; i++){
        maxNum = max(maxNum, nums[i]);
    }

    int left = 1;
    int right = maxNum;
    while (left <= right){
        int middle = (left + right) / 2;
        long middleSum = getSum(nums, numsSize, middle);
        if (middleSum <= threshold && (middle == 1 || getSum(nums, numsSize, middle - 1) > threshold)){
            return middle;
        }

        if (middleSum > threshold){
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }
    }

    return -1;
}

void proof_harness_getSum() {
    int numsSize;
    __CPROVER_assume(numsSize >= 1 && numsSize <= 100);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL); 
    for (int i = 0; i < numsSize; i++) {
        __CPROVER_assume(nums[i] >= 1 && nums[i] <= 1000000000);
    }
    int divizor;
    __CPROVER_assume(divizor >= 1 && divizor <= 1000000000);
    long expectedResult = 0;
    for (int i = 0; i < numsSize; i++){
        int value = nums[i] / divizor;
        if (value * divizor != nums[i]){
            value++;
        }
        expectedResult += value;
    }
    long result = getSum(nums, numsSize, divizor);
    assert(result == expectedResult);
    free(nums);
}

void proof_harness_smallestDivisor() {
    int numsSize;
    __CPROVER_assume(numsSize >= 1 && numsSize <= 100);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL); 
    for (int i = 0; i < numsSize; i++) {
        __CPROVER_assume(nums[i] >= 1 && nums[i] <= 1000000000);
    }
    int threshold;
    __CPROVER_assume(threshold >= 1 && threshold <= 1000000000);
    int expectedResult = 1; // Assume a divisor of 1 will always be valid
    int maxNum = 0;
    for (int i = 0; i < numsSize; i++){
        maxNum = max(maxNum, nums[i]);
    }
    int left = 1;
    int right = maxNum;
    while (left <= right){
        int middle = (left + right) / 2;
        long middleSum = getSum(nums, numsSize, middle);
        if (middleSum <= threshold && (middle == 1 || getSum(nums, numsSize, middle - 1) > threshold)){
            expectedResult = middle;
            break;
        }

        if (middleSum > threshold){
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }
    }
    int result = smallestDivisor(nums, numsSize, threshold);
    assert(result == expectedResult);
    free(nums);
}

void proof_harness_main() {
    int result = main();
    assert(result == 0);
}

void combined_proof_harness() {
    proof_harness_getSum();
    proof_harness_smallestDivisor();
    proof_harness_main();
}