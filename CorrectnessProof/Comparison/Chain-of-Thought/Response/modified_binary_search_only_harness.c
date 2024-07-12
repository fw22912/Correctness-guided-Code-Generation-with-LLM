void proof_harness_modifiedBinarySearch() {
    int n, m, x;
    n = __CPROVER_nondet_int();
    m = __CPROVER_nondet_int();
    x = __CPROVER_nondet_int();
    __CPROVER_assume(n > 0);
    __CPROVER_assume(m > 0);
    int **mat = (int **)malloc(n * sizeof(int *));
    for (int k = 0; k < n; k++)
    {
        mat[k] = (int *)malloc(m * sizeof(int));
    }

void proof_harness_binarySearch() {
    int n, m, x, j_low, j_high, i;
    n = __CPROVER_nondet_int();
    m = __CPROVER_nondet_int();
    x = __CPROVER_nondet_int();
    j_low = __CPROVER_nondet_int();
    j_high = __CPROVER_nondet_int();
    i = __CPROVER_nondet_int();
    __CPROVER_assume(n > 0);
    __CPROVER_assume(m > 0);
    __CPROVER_assume(j_low >= 0);
    __CPROVER_assume(j_high >= 0);
    __CPROVER_assume(j_low <= j_high);
    __CPROVER_assume(j_high < m);
    __CPROVER_assume(i >= 0);
    __CPROVER_assume(i < n);
    int **mat = (int **)malloc(n * sizeof(int *));
    for (int k = 0; k < n; k++)
    {
        mat[k] = (int *)malloc(m * sizeof(int));
    }

