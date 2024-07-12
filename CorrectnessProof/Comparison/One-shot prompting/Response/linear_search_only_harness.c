void proof_harness_linearsearch() {
    int size;
    __CPROVER_assume(size >= 0);
    int *arr = (int *)malloc(size * sizeof(int));
    __CPROVER_assume(arr != NULL);
    int val;
    
    for (int i = 0; i < size; i++) {
        arr[i] = __CPROVER_nondet_int();
    }

