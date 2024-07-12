void proof_harness_fib() {
    int n;
    __CPROVER_assume(n >= 0);
    __CPROVER_assume(n <= 2147483647);
    
    int result = fib(n);
    
    if (n == 0) {
        assert(result == 0);
    }

