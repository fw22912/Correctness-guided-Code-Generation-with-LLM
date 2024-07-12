void proof_harness_sentinel_linear_search() {
    int len;
    __CPROVER_assume(len >= 0);
    int arr[len];
    int key;

    for (int i = 0; i < len; i++) {
        __CPROVER_assume(arr[i] >= 0);
        __CPROVER_assume(arr[i] <= 2147483647);
    }

