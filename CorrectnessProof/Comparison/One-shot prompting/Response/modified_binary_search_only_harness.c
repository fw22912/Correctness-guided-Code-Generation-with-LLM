void proof_harness_binarySearch() {
    int i;
    int j_low;
    int j_high;
    int x;
    int n;
    int m;
    int **mat;
    __CPROVER_assume(n >= 1);
    __CPROVER_assume(m >= 1);
    mat = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        mat[i] = (int *)malloc(m * sizeof(int));
        __CPROVER_assume(mat[i] != NULL);
    }

void proof_harness_modifiedBinarySearch() {
    int n;
    int m;
    int x;
    int **mat;
    __CPROVER_assume(n >= 1);
    __CPROVER_assume(m >= 1);
    mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        mat[i] = (int *)malloc(m * sizeof(int));
        __CPROVER_assume(mat[i] != NULL);
    }

