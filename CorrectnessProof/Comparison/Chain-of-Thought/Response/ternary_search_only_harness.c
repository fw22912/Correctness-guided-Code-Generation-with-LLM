void proof_harness_ternarySearch() {
    int l;
    int r;
    int key;
    int ar[10];
    __CPROVER_assume(l >= 0);
    __CPROVER_assume(r >= 0);
    __CPROVER_assume(r >= l);
    __CPROVER_assume(key >= 0);
    for (int i = 0; i < 10; i++) {
        __CPROVER_assume(ar[i] >= 0);
    }

