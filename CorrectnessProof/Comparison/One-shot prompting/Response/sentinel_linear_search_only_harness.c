void proof_harness_sentinel_linear_search(){
    int len;
    __CPROVER_assume(len > 0 && len <= INT_MAX);
    int *arr = malloc(sizeof(int) * len);
    __CPROVER_assume(arr != NULL);
    int key;
    for (int i = 0; i < len; i++) {
        arr[i] = rand();
    }

