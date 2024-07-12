void proof_harness_interpolationSearch() {
    int n = 15;
    int *arr = malloc(sizeof(int) * n);
    __CPROVER_assume(arr != NULL);
    int key;
    __CPROVER_assume(arr[0] <= key && key <= arr[n-1]);
    for (int i = 0; i < n; i++) {
        __CPROVER_assume(arr[i] <= arr[i+1]); 
    }

