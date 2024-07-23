#include <assert.h>
#include <stdlib.h>

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int i=0;
    int maxCount=0;
    int count = 0;
    
    while(i<numsSize){
        
        while(i<numsSize && nums[i]!=0){
            count++;
            i++;
        }
        
        if(maxCount<=count){
         maxCount = count;   
        }
        
        count = 0;
        while(i<numsSize && nums[i]==0){
            i++;
        }
        
    }
    return maxCount;
    
}

void proof_harness_findMaxConsecutiveOnes() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);

    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }

    int expected_result = findMaxConsecutiveOnes(nums, numsSize);
    int actual_result = findMaxConsecutiveOnes(nums, numsSize);
    assert(expected_result == actual_result);

    free(nums);
}


void proof_harness_main() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);

    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }

    int result = findMaxConsecutiveOnes(nums, numsSize);

    free(nums);
}

void combined_proof_harness() {
    proof_harness_findMaxConsecutiveOnes();
    proof_harness_main();
}