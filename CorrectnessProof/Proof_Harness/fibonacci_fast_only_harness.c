void proof_harness_fib() {
    unsigned long n;
    __CPROVER_assume(n >= 0);
    __CPROVER_assume(n <= 4294967295);

    unsigned long *C = (unsigned long *)malloc(sizeof(unsigned long));
    __CPROVER_assume(C != NULL);
    unsigned long *D = (unsigned long *)malloc(sizeof(unsigned long));
    __CPROVER_assume(D != NULL);

    fib(n, C, D);
    free(C);
    free(D);
}

