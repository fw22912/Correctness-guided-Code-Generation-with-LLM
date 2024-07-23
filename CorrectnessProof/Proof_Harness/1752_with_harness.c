#include <assert.h>
#include <stdlib.h>

bool check(int* nums, int numsSize){
    if (numsSize == 1) {
        return true;
    }
    
    bool wasShift = false;
    for(int i = 1; i < numsSize; i++) {
        if (nums[i - 1] > nums[i]) {
            if (wasShift) {
                return false;
            }

            wasShift = true;
        }
    }
                
    return !wasShift || nums[0] >= nums[numsSize-1];
}

void proof_harness_check() {
    int numsSize;
    __CPROVER_assume(numsSize >= 1);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL); 
    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }
    bool result = check(nums, numsSize);
    free(nums);
}

void proof_harness_main() {
    int numsSize;
    __CPROVER_assume(numsSize >= 1);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL); 
    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }
    bool result = check(nums, numsSize);
    free(nums);
}

void combined_proof_harness() {
    proof_harness_check();
    proof_harness_main();
}