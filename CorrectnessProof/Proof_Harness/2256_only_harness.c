void proof_harness_minimumAverageDifference() {
    int numsSize;
    __CPROVER_assume(numsSize >= 1 && numsSize <= 100000);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        __CPROVER_assume(nums[i] >= -100000 && nums[i] <= 100000);
    }

void combined_proof_harness() {
    proof_harness_minimumAverageDifference();
}

