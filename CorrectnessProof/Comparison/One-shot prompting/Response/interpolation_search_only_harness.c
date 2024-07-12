void proof_harness_interpolationSearch() {
    int n = 15;
    int *arr = (int *)malloc(sizeof(int) * n);
    __CPROVER_assume(arr != NULL); 
    for (int i = 0; i < n; i++) {
        arr[i] = i * 2 + 10;
    }

