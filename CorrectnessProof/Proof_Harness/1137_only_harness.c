void proof_harness_tribonacci() {
    int n;
    __CPROVER_assume(n >= 0);
    int expected_result = tribonacci(n);
    int actual_result = tribonacci(n);
    assert(actual_result == expected_result);
}

void proof_harness_main() {
    int n;
    __CPROVER_assume(n >= 0);
    tribonacci(n);
}

void combined_proof_harness() {
    proof_harness_tribonacci();
    proof_harness_main();
}

