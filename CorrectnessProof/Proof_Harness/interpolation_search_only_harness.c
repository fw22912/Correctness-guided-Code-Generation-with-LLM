void proof_harness_interpolationSearch() {
    int arr[15];
    int n = 15;
    int key;
    __CPROVER_assume(key >= 10);
    __CPROVER_assume(key <= 47);
    for (int i = 0; i < n; i++) {
        __CPROVER_assume(arr[i] >= 10);
        __CPROVER_assume(arr[i] <= 47);
        __CPROVER_assume(arr[i] < arr[i+1]);
    }

