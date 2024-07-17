void proof_harness_bead_sort() {
    size_t len;
    __CPROVER_assume(len > 0);
    int *a = (int *)malloc(len * sizeof(int));
    __CPROVER_assume(a != NULL);
    for (size_t i = 0; i < len; i++) {
        __CPROVER_assume(a[i] >= 0);
    }

