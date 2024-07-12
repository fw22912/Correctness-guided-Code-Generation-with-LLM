void proof_harness_fibMonaccianSearch() {
    int n;
    __CPROVER_assume(n > 0);
    int x;
    int *arr = malloc(sizeof(int) * n);
    __CPROVER_assume(arr != NULL);
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }

