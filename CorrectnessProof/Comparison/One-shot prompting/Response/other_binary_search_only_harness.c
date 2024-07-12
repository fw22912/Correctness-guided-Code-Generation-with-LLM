void proof_harness_binarySearch() {
    int array[len];
    int leng;
    int searchX;
    __CPROVER_assume(leng >= 0);
    __CPROVER_assume(leng <= len);
    for (int i = 0; i < len; i++) {
        array[i] = rand();
    }

