void proof_harness_findDuplicate() {
    int numsSize;
    __CPROVER_assume(numsSize > 1);
    int *nums = (int *)malloc(numsSize * sizeof(int));
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        __CPROVER_assume(nums[i] >= 0 && nums[i] <= numsSize - 1);
    }

