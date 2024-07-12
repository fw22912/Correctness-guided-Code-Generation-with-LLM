void proof_harness_binarySearch() {
        int array[len];
        int leng;
        int searchX;
        __CPROVER_assume(leng >= 0);
        __CPROVER_assume(leng <= 5);
        __CPROVER_assume(searchX >= 0);
        __CPROVER_assume(searchX <= 2147483647);
        for (int i = 0; i < len; i++) {
            __CPROVER_assume(array[i] >= 0);
            __CPROVER_assume(array[i] <= 2147483647);
        }

