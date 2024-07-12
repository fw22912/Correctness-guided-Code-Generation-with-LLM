void proof_harness_fibMonaccianSearch() {
        int x;
        int n;
        __CPROVER_assume(n >= 0);
        __CPROVER_assume(n <= 2147483647);
        int *arr = (int *)malloc(sizeof(int) * n);
        __CPROVER_assume(arr != NULL);
        for(int i = 0; i < n; ++i) {
            arr[i] = i;
        }

