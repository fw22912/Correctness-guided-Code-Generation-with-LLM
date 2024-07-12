void proof_harness_binarysearch2() {
    int l;
    int r;
    int x;
    int *arr;
    int n;
    __CPROVER_assume(l >= 0);
    __CPROVER_assume(r >= 0);
    __CPROVER_assume(l <= r);
    __CPROVER_assume(x >= 0);
    __CPROVER_assume(x <= 2147483647);
    n = r - l + 1;
    arr = (int *)malloc(sizeof(int) * n);
    __CPROVER_assume(arr != NULL);
    for (int i = 0; i < n; i++) {
        __CPROVER_assume(arr[i] >= 0);
        __CPROVER_assume(arr[i] <= 2147483647);
    }

void proof_harness_binarysearch1() {
    int l;
    int r;
    int x;
    int *arr;
    int n;
    __CPROVER_assume(l >= 0);
    __CPROVER_assume(r >= 0);
    __CPROVER_assume(l <= r);
    __CPROVER_assume(x >= 0);
    __CPROVER_assume(x <= 2147483647);
    n = r - l + 1;
    arr = (int *)malloc(sizeof(int) * n);
    __CPROVER_assume(arr != NULL);
    for (int i = 0; i < n; i++) {
        __CPROVER_assume(arr[i] >= 0);
        __CPROVER_assume(arr[i] <= 2147483647);
    }

