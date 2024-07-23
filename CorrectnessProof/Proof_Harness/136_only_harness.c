void combined_proof_harness() {
    proof_harness_singleNumber();
    proof_harness_main();
}

void proof_harness_singleNumber() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = rand();
    }

void proof_harness_main() {
    int numsSize = 1;
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    nums[0] = 2;
    int result = singleNumber(nums, numsSize);
    assert(result == 2);
    free(nums);
}

