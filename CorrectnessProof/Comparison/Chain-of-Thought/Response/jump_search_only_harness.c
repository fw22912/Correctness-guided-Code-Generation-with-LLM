void proof_harness_jump_search() {
    size_t n;
    __CPROVER_assume(n > 0);
    int *arr = (int *)malloc(sizeof(int) * n);
    __CPROVER_assume(arr != NULL);
    int x;

    for (size_t i = 0; i < n; i++) {
        arr[i] = i;
    }

