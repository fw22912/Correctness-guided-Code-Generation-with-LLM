#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define max(a,b) (((a)>(b))?(a):(b))

int compare(const int* i, const int* j)
{
    return *i - *j;
}

// Sort + prefix sum + windows sliding
// Runtime: O(n*log(n))
// Space: O(n)
int maxFrequency(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof (int), (int(*) (const void*, const void*)) compare);
    long* prefixSum = malloc(numsSize * sizeof(long));
    
    prefixSum[0] = nums[0];
    for(int i = 0; i < numsSize - 1; i++){
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    int leftWindowPosition = 0;
    int result = 0;
    
    for(int rightWindowPosition = 0; rightWindowPosition < numsSize; rightWindowPosition++){
        long rightSum = prefixSum[rightWindowPosition];
        long leftSum = prefixSum[leftWindowPosition];

        while ((long)nums[rightWindowPosition] * (rightWindowPosition - leftWindowPosition) - (rightSum - leftSum) > k){
            leftWindowPosition += 1;
        }

        result = max(result, rightWindowPosition - leftWindowPosition + 1);
    }

    free(prefixSum);
    return result;
}

void proof_harness_compare() {
    int i, j;
    __CPROVER_assume(i >= 0);
    __CPROVER_assume(j >= 0);
    int* iPtr = &i;
    int* jPtr = &j;
    int result = compare(iPtr, jPtr);
    assert(result == i - j);
}

void proof_harness_maxFrequency() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int* nums = (int*) malloc(numsSize * sizeof(int));
    __CPROVER_assume(nums != NULL);
    int k;
    __CPROVER_assume(k >= 0);
    int result = maxFrequency(nums, numsSize, k);
    free(nums);
}

void proof_harness_main() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int* nums = (int*) malloc(numsSize * sizeof(int));
    __CPROVER_assume(nums != NULL);
    int k;
    __CPROVER_assume(k >= 0);
    int result = maxFrequency(nums, numsSize, k);
    free(nums);
}

void combined_proof_harness() {
    proof_harness_compare();
    proof_harness_maxFrequency();
    proof_harness_main();
}