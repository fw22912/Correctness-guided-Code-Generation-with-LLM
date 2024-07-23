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

void combined_proof_harness() {
    proof_harness_compare();
    proof_harness_maxFrequency();
    proof_harness_main();
}

