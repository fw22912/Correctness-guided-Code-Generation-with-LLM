void proof_harness_duplicateNumber() {
    size_t n;
    __CPROVER_assume(n >= 2);
    __CPROVER_assume(n <= 2147483647);
    uint32_t *in_arr = (uint32_t *)malloc(sizeof(uint32_t) * n);
    __CPROVER_assume(in_arr != NULL);
    for (size_t i = 0; i < n; i++) {
        __CPROVER_assume(in_arr[i] >= 1);
        __CPROVER_assume(in_arr[i] <= n);
    }

