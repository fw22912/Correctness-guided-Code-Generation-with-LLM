void proof_harness_threeSumClosest() {
    int nums_size;
    __CPROVER_assume(nums_size > 2);
    int *nums = (int*)malloc(sizeof(int) * nums_size);
    __CPROVER_assume(nums != NULL);
    int target;
    for (int i = 0; i < nums_size; i++) {
        nums[i] = __CPROVER_nondet_int();
    }

void combined_proof_harness() {
    proof_harness_threeSumClosest();
    proof_harness_cmp();
}

void proof_harness_cmp() {
    int a = __CPROVER_nondet_int();
    int b = __CPROVER_nondet_int();
    int result = cmp(&a, &b);
    if (a > b) {
        assert(result == 1);
    }

