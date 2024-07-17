void proof_harness_duplicateNumber() {
    size_t n;
    uint32_t *in_arr;
    __CPROVER_assume(n > 1);
    in_arr = (uint32_t *) malloc(n * sizeof(uint32_t));
    __CPROVER_assume(in_arr != NULL);
    for (size_t i = 0; i < n; ++i) {
        __CPROVER_assume(in_arr[i] >= 1 && in_arr[i] <= n);
    }

