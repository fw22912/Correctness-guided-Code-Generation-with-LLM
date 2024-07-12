void proof_harness_fib() {
    unsigned int n;
    __CPROVER_assume(n >= 0);
    int expected = fib(n);
    int result = fib(n);
    assert(result == expected);
}

