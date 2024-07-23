#include <assert.h>
#include <stdlib.h>

// Prefix sum.
// Collect sum fromleft part and compare it with left sum.
// Runtime: O(n)
// Space: O(1)
int waysToSplitArray(int* nums, int numsSize){
    long sumNums = 0;
    for (int i = 0; i < numsSize; i++){
        sumNums += nums[i];
    }
    
    long prefixSum = 0;
    int result = 0;
    for (int i = 0; i < numsSize - 1; i++){
        prefixSum += nums[i];
        if (prefixSum >= sumNums - prefixSum){
            result += 1;
        }
    }

    return result;
}

void proof_harness_waysToSplitArray() {
    int numsSize;
    __CPROVER_assume(numsSize >= 1);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = __CPROVER_nondet_int();
    }
    int result = waysToSplitArray(nums, numsSize);
    free(nums);
}


void proof_harness_main() {
    int argc = __CPROVER_nondet_int();
    char** argv = (char**)malloc(sizeof(char*) * argc);
    __CPROVER_assume(argv != NULL);
    for (int i = 0; i < argc; i++) {
        argv[i] = (char*)malloc(sizeof(char) * 100);
        __CPROVER_assume(argv[i] != NULL);
    }
    main(argc, argv);
    for (int i = 0; i < argc; i++) {
        free(argv[i]);
    }
    free(argv);
}

void combined_proof_harness() {
    proof_harness_waysToSplitArray();
    proof_harness_main();
}