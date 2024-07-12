void proof_harness_main() {
    int n;
    __CPROVER_assume(n >= 0);
    __CPROVER_assume(n <= 2147483647);
    int i, test = 0, count = 0;
    for (i = 1;; i++) {
        test = n / pow(5, i);
        if (test != 0) {
            count = count + test;
        }

