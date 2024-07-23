void proof_harness_longestSquareStreak() {
    int numsSize;
    __CPROVER_assume(numsSize >= 1 && numsSize <= 100);
    int* nums = (int*)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        __CPROVER_assume(nums[i] >= 0 && nums[i] <= 100);
    }

void proof_harness_main() {
    int result = main();
    assert(result == 0);
}

void proof_harness_longestSquareStreakDp() {
    int numsSetSize;
    __CPROVER_assume(numsSetSize >= 1 && numsSetSize <= 100);
    int* numsSet = (int*)malloc(sizeof(int) * numsSetSize);
    __CPROVER_assume(numsSet != NULL);
    for (int i = 0; i < numsSetSize; i++) {
        __CPROVER_assume(numsSet[i] >= 0 && numsSet[i] <= 100);
    }

void combined_proof_harness() {
    proof_harness_longestSquareStreakDp();
    proof_harness_longestSquareStreak();
    proof_harness_main();
}

