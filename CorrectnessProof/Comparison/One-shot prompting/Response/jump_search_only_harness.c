void proof_harness_jump_search() {
    int n;
    __CPROVER_assume(n > 0);
    int *arr = (int *)malloc(sizeof(int) * n);
    __CPROVER_assume(arr != NULL); 
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

