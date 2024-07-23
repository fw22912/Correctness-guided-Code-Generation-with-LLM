void combined_proof_harness() {
    proof_harness_containsDuplicate();
    proof_harness_numcmp();
}

void proof_harness_numcmp() {
    int a = rand();
    int b = rand();
    int expected_result = a - b;
    int actual_result = numcmp(&a, &b);
    assert(actual_result == expected_result);
}

void proof_harness_containsDuplicate() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    __CPROVER_assume(nums != NULL);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = rand();
    }

