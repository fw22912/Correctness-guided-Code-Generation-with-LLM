void combined_proof_harness() {
    proof_harness_singleNonDuplicate();
}

void proof_harness_singleNonDuplicate() {
    int numsSize;
    __CPROVER_assume(numsSize > 0);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);

    for (int i = 0; i < numsSize; i++) {
        __CPROVER_assume(i % 2 == 0 ? nums[i] != nums[i + 1] : nums[i] != nums[i - 1]);
    }

