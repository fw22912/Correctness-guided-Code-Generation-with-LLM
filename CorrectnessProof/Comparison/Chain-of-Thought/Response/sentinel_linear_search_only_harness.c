void proof_harness_sentinel_linear_search(){
    int len;
    int key;
    __CPROVER_assume(len > 0);
    int *arr = (int *)malloc(sizeof(int) * len);
    __CPROVER_assume(arr != NULL);

    for (int i = 0; i < len; i++) {
        arr[i] = i;
    }

