void proof_harness_ternarySearch() {
    int l, r, key;
    __CPROVER_assume(l >= 0);
    __CPROVER_assume(r >= 0);
    __CPROVER_assume(l <= r);
    __CPROVER_assume(key >= 0);
    __CPROVER_assume(key <= 2147483647);
    
    int ar[10];
    for (int i = 0; i < 10; i++) {
        __CPROVER_assume(ar[i] >= 0);
        __CPROVER_assume(ar[i] <= 2147483647);
    }

