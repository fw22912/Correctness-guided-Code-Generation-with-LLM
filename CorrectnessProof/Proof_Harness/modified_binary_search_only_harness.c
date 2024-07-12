void proof_harness_modifiedBinarySearch() {
    int n, m, x;
    const int **mat;
    __CPROVER_assume(n >= 1);
    __CPROVER_assume(n <= 2147483647);
    __CPROVER_assume(m >= 1);
    __CPROVER_assume(m <= 2147483647);
    __CPROVER_assume(x >= 0);
    __CPROVER_assume(x <= 2147483647);
    mat = (const int **)malloc(n * sizeof(int *));
    __CPROVER_assume(mat != NULL);
    for (int i = 0; i < n; i++) {
        mat[i] = (const int *)malloc(m * sizeof(int));
        __CPROVER_assume(mat[i] != NULL);
    }

void proof_harness_binarySearch() {
    int i, j_low, j_high, x;
    const int **mat;
    __CPROVER_assume(i >= 0);
    __CPROVER_assume(i <= 2147483647);
    __CPROVER_assume(j_low >= 0);
    __CPROVER_assume(j_low <= 2147483647);
    __CPROVER_assume(j_high >= 0);
    __CPROVER_assume(j_high <= 2147483647);
    __CPROVER_assume(x >= 0);
    __CPROVER_assume(x <= 2147483647);
    mat = (const int **)malloc(sizeof(int *));
    __CPROVER_assume(mat != NULL);
    mat[0] = (const int *)malloc(sizeof(int));
    __CPROVER_assume(mat[0] != NULL);
    binarySearch(mat, i, j_low, j_high, x);
    free(mat[0]);
    free(mat);
}

