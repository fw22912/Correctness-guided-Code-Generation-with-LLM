void proof_harness_duplicateNumber() {
        size_t n;
        __CPROVER_assume(n > 1);
        uint32_t *in_arr = (uint32_t *)malloc(sizeof(uint32_t) * n);
        if (in_arr == NULL) {
            return;
        }

