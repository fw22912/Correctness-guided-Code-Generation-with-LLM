void combined_proof_harness() {
    proof_harness_findDuplicates();
    proof_harness_cmpval();
}

void proof_harness_cmpval() {
    int a, b;
    __CPROVER_assume(a >= 0);
    __CPROVER_assume(b >= 0);
    int res = cmpval(&a, &b);
    assert(res == a - b);
}

void proof_harness_findDuplicates() {
    int numsSize;
    __CPROVER_assume(numsSize >= 0);
    int *nums = malloc(numsSize * sizeof(int));
    __CPROVER_assume(nums != NULL);
    int returnSize;
    int *retArr = findDuplicates(nums, numsSize, &returnSize);
    free(nums);
    free(retArr);
}

