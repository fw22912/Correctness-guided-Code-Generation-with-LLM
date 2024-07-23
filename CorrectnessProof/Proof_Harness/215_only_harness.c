void combined_proof_harness() {
    proof_harness_findKthLargest();
}

void proof_harness_findKthLargest() {
    int numsSize;
    int k;
    __CPROVER_assume(numsSize >= 1);
    __CPROVER_assume(k >= 1);
    __CPROVER_assume(k <= numsSize);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = nondet_int();
    }

