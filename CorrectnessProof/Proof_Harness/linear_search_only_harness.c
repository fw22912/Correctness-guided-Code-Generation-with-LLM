void proof_harness_linearsearch() {
        int size;
        __CPROVER_assume(size >= 0);
        int val;
        __CPROVER_assume(val >= 0);
        __CPROVER_assume(val <= 2147483647);
    
        int *arr = (int *)malloc(size * sizeof(int));
        __CPROVER_assume(arr != NULL);
        for (int i = 0; i < size; i++) {
            arr[i] = rand();
        }

