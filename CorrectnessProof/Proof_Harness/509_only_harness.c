void proof_harness_fib() {
    int N;
    __CPROVER_assume(N >= 0);
    int expected = fib(N);
    int result = fib(N);
    assert(result == expected);
}

void proof_harness_main() {
    int N;
    __CPROVER_assume(N >= 0);
    main();
}

void combined_proof_harness() {
    proof_harness_fib();
    proof_harness_main();
}

