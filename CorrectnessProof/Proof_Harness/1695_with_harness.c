#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Window sliding. Runtime: O(n), Space: O(n)
int maximumUniqueSubarray(int* nums, int numsSize){
    short* numsSet = (short*)calloc(10001, sizeof(short));
    numsSet[nums[0]] = 1;

    int maxSum = nums[0];

    int windowSumm = maxSum;
    int leftIndex = 0;
    
    int num = 0;
    for(int i = 1; i < numsSize; i++){
        num = nums[i];
        while (numsSet[num] != 0){
            numsSet[nums[leftIndex]] = 0;
            windowSumm -= nums[leftIndex];
            leftIndex++;
        }
        
        numsSet[num] = 1;
        windowSumm += num;
            
        if (maxSum < windowSumm){
            maxSum = windowSumm;
        }
    }
    
    return maxSum;
}

void proof_harness_maximumUniqueSubarray(){
    int numsSize;
    __CPROVER_assume(numsSize >= 1 && numsSize <= 10000);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        __CPROVER_assume(nums[i] >= 0 && nums[i] <= 10000);
    }
    int result = maximumUniqueSubarray(nums, numsSize);
    free(nums);
}


void combined_proof_harness(){
    proof_harness_maximumUniqueSubarray();
}