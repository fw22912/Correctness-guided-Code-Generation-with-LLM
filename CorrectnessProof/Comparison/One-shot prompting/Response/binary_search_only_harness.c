void proof_harness_binarysearch2() {
    int *arr;
    int l;
    int r;
    int x;
    int n;

    arr = (int *)malloc(sizeof(int) * 10);
    __CPROVER_assume(arr != NULL);
    n = __CPROVER_nondet_int();
    __CPROVER_assume(n >= 0 && n <= 10);
    for (int i = 0; i < n; i++) {
        arr[i] = __CPROVER_nondet_int();
    }

void proof_harness_binarysearch1() {
    int *arr;
    int l;
    int r;
    int x;
    int n;

    arr = (int *)malloc(sizeof(int) * 10);
    __CPROVER_assume(arr != NULL);
    n = __CPROVER_nondet_int();
    __CPROVER_assume(n >= 0 && n <= 10);
    for (int i = 0; i < n; i++) {
        arr[i] = __CPROVER_nondet_int();
    }

