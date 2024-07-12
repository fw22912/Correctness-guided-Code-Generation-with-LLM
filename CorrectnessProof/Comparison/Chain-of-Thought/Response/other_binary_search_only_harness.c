void proof_harness_binarySearch() {
    int array[len];
    int leng;
    int searchX;
    
    __CPROVER_assume(leng >= 0 && leng <= len);
    for (int i = 0; i < leng; i++) {
        __CPROVER_assume(array[i] >= 0 && array[i] <= 255);
    }

