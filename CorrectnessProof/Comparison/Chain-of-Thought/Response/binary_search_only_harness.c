void proof_harness_binarysearch1() {
    int *arr = (int *)malloc(sizeof(int) * 10);
    __CPROVER_assume(arr != NULL);
    int l = 0;
    __CPROVER_assume(l >= 0);
    __CPROVER_assume(l < 10);
    int r = 9;
    __CPROVER_assume(r >= 0);
    __CPROVER_assume(r < 10);
    int x;
    for (int i = 0; i < 10; i++) {
        __CPROVER_assume(arr[i] >= 0);
        __CPROVER_assume(arr[i] <= 2147483647);
    }

void proof_harness_binarysearch2() {
    int *arr = (int *)malloc(sizeof(int) * 10);
    __CPROVER_assume(arr != NULL);
    int l = 0;
    __CPROVER_assume(l >= 0);
    __CPROVER_assume(l < 10);
    int r = 9;
    __CPROVER_assume(r >= 0);
    __CPROVER_assume(r < 10);
    int x;
    for (int i = 0; i < 10; i++) {
        __CPROVER_assume(arr[i] >= 0);
        __CPROVER_assume(arr[i] <= 2147483647);
    }

